#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {
class FunctionInfo : public ModulePass
{
public:
	static char ID;

	FunctionInfo() : ModulePass(ID) {}
	virtual ~FunctionInfo() {}
  	// We don't modify the program, so we preserve all analysis.
	virtual void getAnalysisUsage(AnalysisUsage & AU) const override final
	{
		AU.setPreservesAll();
	}
	virtual bool runOnModule(Module & M) override final
	{
		outs() << "CSCD70 Functions Information Pass" << "\n";

		// @TODO Please complete this function.
		
		return false;
	}
};  // class FunctionInfo
}  // namespace anonymous
char FunctionInfo::ID = 0;
RegisterPass < FunctionInfo > X (
	"function-info",
	"CSCD70: Functions Information"
);
