#pragma once

#include "Workflow.h"

class WorkflowExecutor {
public:
	WorkflowExecutor() = default;
	~WorkflowExecutor() = default;

	void run(Workflow w) const;
};
