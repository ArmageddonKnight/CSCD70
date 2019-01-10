#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {
class FunctionInfo : public ModulePass
{
private:
	
	bool runOnFunction(Function & F)
	{
		return false;
	}
	
public:
	static char ID;

	FunctionInfo() : ModulePass(ID)
	{}

	~FunctionInfo()
	{}

  	// We don't modify the program, so we preserve all analysis.
	virtual void getAnalysisUsage(AnalysisUsage & AU) const
	{
		AU.setPreservesAll();
	}
  
	virtual bool runOnModule(Module & M)
	{
		outs() << "CSCD70 Functions Information Pass" << "\n";

		for (Module::iterator iter = M.begin(); iter != M.end(); ++iter)
		{
			runOnFunction(*iter);
		}
		
		return false;
	}
};

char FunctionInfo::ID = 0;

RegisterPass < FunctionInfo > X ("function-info", "CSCD70: Functions Information");

} // Anonymous Namespace