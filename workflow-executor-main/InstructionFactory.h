#pragma once
#include <string>
#include <map>
#include <stdexcept>
#include <functional>

class Instruction;

class InstructionFactory {
public:
	typedef std::function<Instruction*()> Builder;

	static InstructionFactory& getInstance() {
		static InstructionFactory _instance;
		return _instance;
	}

	template<typename Mutation>
	bool Register(std::string const& key) {
		return this->_map.insert(std::make_pair(key, [](){ return new Mutation(); })).second;
	}
	
	Instruction* Build(std::string const& key) const {
		auto it = _map.find(key);
		if (it == _map.end()) { 
			throw std::invalid_argument("no Instruction at key `" + key + '`'); 
		}
		return it->second();
	}
private:
	InstructionFactory() = default;

	static InstructionFactory _instance;
	std::map<std::string, Builder> _map;
public:
	InstructionFactory(InstructionFactory const&) = delete;
	void operator=(InstructionFactory const&) = delete;
};
