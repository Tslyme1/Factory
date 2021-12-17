#pragma once
#include "Instruction.h"

#include <unordered_map>
#include <vector>
#include <string>

typedef struct Workflow {
	std::unordered_map<size_t, std::vector<std::string> > instruction_args;
	std::unordered_map<size_t, Instruction*> instruction_bind;
	std::vector<size_t> order;
} Workflow;
