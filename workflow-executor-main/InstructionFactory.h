#pragma once
#include <string>
#include <map>
#include <stdexcept>

class Instruction;

class InstructionFactory {
public:
	static InstructionFactory& getInstance() {
		static InstructionFactory _instance;
		return _instance;
	}

	bool Register(std::string const& key, Instruction* instruction) {
		return this->_map.insert(std::make_pair(key, instruction)).second;
	}
	
	Instruction* Build(std::string const& key) const {
		auto it = _map.find(key);
		if (it == _map.end()) { 
			throw std::invalid_argument("no Instruction at key `" + key + '`'); 
		}
		return it->second;
	}
private:
	InstructionFactory() = default;

	static InstructionFactory _instance;
	std::map<std::string, Instruction*> _map;
public:
	InstructionFactory(InstructionFactory const&) = delete;
	void operator=(InstructionFactory const&) = delete;
};
