#include "WorkflowExecutor.h"
#include "Workflow.h"
#include "InstructionFactory.h"

#include <stdexcept>
#include <iostream>

void WorkflowExecutor::run(Workflow w) const {
	bool data_flows = false;
	std::string text = "";
	
	InstructionFactory& Factory = InstructionFactory::getInstance();
	for (size_t id : w.order) {
		Instruction* istruct = Factory.Build(w.instruction_bind[id]);
		const auto p = istruct->getProtocol();
		
		if (data_flows != p.takes) {
			throw std::invalid_argument("wrong instruction order at bind `" 
			                            + std::to_string(id) + " = " + w.instruction_bind[id] + "`");
		}

		istruct->execute(text, w.instruction_args[id]);

		data_flows = p.returns;
	}
};
