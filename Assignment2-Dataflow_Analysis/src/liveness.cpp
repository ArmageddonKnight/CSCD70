#include "dfa/framework.h"

// @TODO 

namespace {
class Liveness : public FunctionPass // @TODO Change the base class if necessary.
{
public:
	static char ID;

	Liveness() : FunctionPass(ID) {}

	// @TODO Add or remove method definitions if necessary.
	
	virtual void getAnalysisUsage(AnalysisUsage & AU) const
	{
		AU.setPreservesAll();
	}

	bool runOnFunction(Function & func)
	{
		return false;
	}
};

char Liveness::ID = 1; 
RegisterPass < Liveness > Y ("liveness", "Liveness");
} // namespace anonymous