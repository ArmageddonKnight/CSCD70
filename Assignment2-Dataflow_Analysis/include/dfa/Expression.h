#ifndef DFA_EXPRESSION_H
#define DFA_EXPRESSION_H

#include <functional>

#include <llvm/IR/Instruction.h>
#include <llvm/IR/Value.h>
#include <llvm/Support/raw_ostream.h>

using namespace llvm;


namespace dfa {

/**
 * @brief A wrapper for expressions.
 */
class Expression {
 private:
  const unsigned Opcode;
  const Value* LHS = nullptr, * RHS = nullptr;
 public:
  /// @todo(cscd70) Please complete the constructor and the comparator.
  Expression(const Instruction& Inst) : Opcode(Inst.getOpcode()) {


  }
  bool operator==(const Expression& Expr) const {


    return false;
  }
  unsigned getOpcode() const { return Opcode; }
  const Value* getLHSOperand() const { return LHS; }
  const Value* getRHSOperand() const { return RHS; }
};

inline raw_ostream& operator<<(raw_ostream& Outs, const Expression& Expr) {
  Outs << "[" << Instruction::getOpcodeName(Expr.getOpcode()) << " ";
  Expr.getLHSOperand()->printAsOperand(Outs, false);
  Outs << ", ";
  Expr.getRHSOperand()->printAsOperand(Outs, false);
  Outs << "]";
  return Outs;
}

}  // namespace dfa

namespace std {

/**
 * @brief  Construct a hash code for @c dfa::Expression .
 */
template <>
struct hash<::dfa::Expression> {
  size_t operator()(const ::dfa::Expression& Expr) const {
    hash<unsigned> UnsignedHasher;
    hash<const Value*> PValueHasher;
    size_t OpcodeHashVal = UnsignedHasher(Expr.getOpcode());
    size_t LHSOperandHashVal = PValueHasher((Expr.getLHSOperand()));
    size_t RHSOperandHashVal = PValueHasher((Expr.getRHSOperand()));
    return OpcodeHashVal ^ (LHSOperandHashVal << 1) ^ (RHSOperandHashVal << 1);
  }
};

}  // namespace std

#endif  // DFA_EXPRESSION_H
