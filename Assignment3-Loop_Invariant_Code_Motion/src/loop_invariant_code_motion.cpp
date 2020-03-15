#include "./dominators.h"

#include <llvm/Analysis/LoopPass.h>

using namespace llvm;


namespace {

class LoopInvariantCodeMotion final : public LoopPass
{
public:
        static char ID;

	LoopInvariantCodeMotion() : LoopPass(ID) {}
	virtual ~LoopInvariantCodeMotion() override {}

        virtual void getAnalysisUsage(AnalysisUsage & AU) const
	{
		AU.setPreservesCFG();
	}

        virtual bool runOnLoop(Loop * L, LPPassManager & LPM)
	{
                
        }
};

}  // namespace anonymous
