#include "WorkflowExecutor.h"
#include "WorkflowParser.h"
#include "Workflow.h"

#include <iostream>

int main() {
    std::string file_name;
    std::cin >> file_name;

    try {
        WorkflowParser wp;

        std::cout << "Parsing!\n";
        Workflow w = wp.parse(file_name);

        WorkflowExecutor we;

        std::cout << "Running!\n";
        we.run(w);
    }
    catch (std::exception& e) {
        std::cout << "Failed with message \'" + std::string(e.what()) + "\'";
        return 0;
    }

    std::cout << "Done!\n";
    return 0;
}
