#pragma once
#include "InstructionFactory.h"

#include <iostream>
#include <string>
#include <vector>

typedef struct Protocol { bool takes; bool returns; } Protocol;

class Instruction {
public:
	virtual void execute(std::string& text, std::vector<std::string> args) = 0;
	virtual const Protocol getProtocol() = 0;
};

class Readfile : public Instruction {
	void execute(std::string& text, std::vector<std::string> args) override;
	inline const Protocol getProtocol() {return Protocol{ false, true };}
};

class Grep : public Instruction {
	void execute(std::string& text, std::vector<std::string> args) override;
	inline const Protocol getProtocol() { return Protocol{ true, true }; };
};

class Sort : public Instruction {
	void execute(std::string& text, std::vector<std::string> args) override;
	inline const Protocol getProtocol() { return Protocol{ true, true }; };
};

class Replace : public Instruction {
	void execute(std::string& text, std::vector<std::string> args) override;
	inline const Protocol getProtocol() { return Protocol{ true, true }; };
};

class DataWriter : public Instruction {
	void execute(std::string& text, std::vector<std::string> args) override;
};

class Writefile : public DataWriter {
	inline const Protocol getProtocol() { return Protocol{ true, false }; };
};

class Dump : public DataWriter {
	inline const Protocol getProtocol() { return Protocol{ true, true }; };
};

namespace {
	bool registerInstructions() {
		InstructionFactory& Factory = InstructionFactory::getInstance();

		Factory.Register<Readfile>("readfile");
		Factory.Register<Writefile>("writefile");
		Factory.Register<Grep>("grep");
		Factory.Register<Sort>("sort");
		Factory.Register<Replace>("replace");
		Factory.Register<Dump>("dump");

		return true;
	}

	static bool fakeVar = registerInstructions();
}
