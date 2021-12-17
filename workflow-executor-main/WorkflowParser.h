#pragma once

#include "Workflow.h"

class WorkflowParser {
public:
	Workflow parse(const std::string file_name) const;
};
