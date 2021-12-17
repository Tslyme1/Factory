#include "WorkflowExecutor.h"
#include "Workflow.h"

#include <iostream>
#include <tuple>
#include <utility>
#include <functional>

void WorkflowExecutor::run(Workflow w) const {
	std::string text = "";
	
	for (size_t id : w.order) {
		w.instruction_bind[id]->execute(text, w.instruction_args[id]);
	}
};
