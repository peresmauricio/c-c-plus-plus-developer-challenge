#include "parser.h"
#include <stack>
#include <sstream>
#include <cctype>
#include <stdexcept>

namespace exprlib {

int Parser::precedence(const std::string& op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*") return 2;
    return 0;
}

bool Parser::isOperator(const std::string& t) {
    if (t == "+" || t == "-" || t == "*" || t == "det" ||
        t == "("|| t == ")") return true;

    return false;
}

bool Parser::isNumberToken(const std::string& t) {
    if (t.empty()) return false;
    
    if(Parser::isOperator(t)) return false;

    return true;
}


NodePtr Parser::parseInfix(const std::string& expr) {
    // guarda a sub-árvore. NodePtr - aponta para um nó  (valor ou árvore montada) 
    std::stack<NodePtr> values;
    // Guarda um operador pendente (stack)
    std::stack<std::string> ops;
    // Quebra a string por espaços 3 + 5 * 2" -> (3,+,5,*,2)
    std::istringstream iss(expr);
    std::string tok;
    

    // Define the function to reduce 
    auto reduceTop = [&]() {
        if (ops.empty()) throw std::runtime_error("Operador ausente.");
        if (values.size() < 2) throw std::runtime_error("Operandos insuficientes.");

        auto op = ops.top(); ops.pop();
        auto right = std::move(values.top()); values.pop();
        //right->sym.setType(Symbol::Type::VALUE);
        auto left  = std::move(values.top()); values.pop();
        //left->sym.setType(Symbol::Type::VALUE);
        values.push(makeOp(op, std::move(left), std::move(right)));
        values.top()->sym.setType(Symbol::Type::OPERATION);
    };

    while (iss >> tok) {
        if (isNumberToken(tok)) {
            values.push(std::make_unique<Node>(Symbol(tok)));
            values.top()->sym.setType(Symbol::Type::VALUE);
        }
        else if (tok == "(") {
            ops.push(tok);
        }
        else if (tok == ")") {
            while (!ops.empty() && ops.top() != "(") reduceTop();
            if (ops.empty()) throw std::runtime_error("Parênteses desalinhados.");
            ops.pop(); // remove "("
        }
        else {
            // operador
            while (!ops.empty() && ops.top() != "(" && 
                precedence(ops.top()) >= precedence(tok))
            {
                reduceTop();
            }
            ops.push(tok);
        }
    }

    while (!ops.empty()) {
        if (ops.top() == "(") throw std::runtime_error("Parênteses desalinhados.");
        reduceTop();
    }

    if (values.size() != 1) throw std::runtime_error("Expressão inválida.");
    return std::move(values.top());
}

} // namespace exprlib