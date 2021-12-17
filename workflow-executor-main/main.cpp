#include "WorkflowExecutor.h"
#include "WorkflowParser.h"
#include "Workflow.h"

#include <iostream>

int main() {
    
    std::string file_name;
    std::cin >> file_name;

    WorkflowParser wp;

    std::cout << "Parsing!\n";

    Workflow w = wp.parse(file_name);

    WorkflowExecutor we;

    std::cout << "Running!\n";
    we.run(w);

    std::cout << "Done!\n";
}
