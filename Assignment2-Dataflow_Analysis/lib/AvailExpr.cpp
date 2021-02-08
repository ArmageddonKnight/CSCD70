/**
 * @file Available Expression Dataflow Analysis
 */
#include <llvm/IR/Instructions.h>
#include <llvm/Pass.h>

#include "Expression.h"
#include "dfa/Framework.h"

using namespace dfa;
using namespace llvm;

namespace {

using AvailExprFrameworkBase =
    Framework<Expression, bool, Direction::kForward, Intersect>;

class AvailExpr final : public AvailExprFrameworkBase, public FunctionPass {
private:
  virtual void initializeDomainFromInst(const Instruction &Inst) override {
    if (auto *const BinaryOp = dyn_cast<BinaryOperator>(&Inst)) {
      /**
       * @todo(cscd70) Please complete the construction of domain.
       */
    }
  }
  virtual bool transferFunc(const Instruction &Inst,
                            const std::vector<bool> &IBV,
                            std::vector<bool> &OBV) override {
    /**
     * @todo(cscd70) Please complete the definition of the transfer function.
     */

    return false;
  }

public:
  static char ID;

  AvailExpr() : AvailExprFrameworkBase(), FunctionPass(ID) {}
  virtual ~AvailExpr() override {}

  virtual void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.setPreservesAll();
  }
  bool runOnFunction(Function &F) override {
    return AvailExprFrameworkBase::runOnFunction(F);
  }
};

char AvailExpr::ID = 1;
RegisterPass<AvailExpr> X("avail-expr", "Available Expression");

} // anonymous namespace
