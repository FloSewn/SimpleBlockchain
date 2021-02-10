#include "Blockchain.h"

Blockchain::Blockchain()
{
  vChain_.emplace_back(Block(0, "Genesis Block"));
  nDifficulty_ = 5;
}

void Blockchain::AddBlock(Block bNew)
{
  bNew.sPrevHash = GetLastBlock_().GetHash();
  bNew.MineBlock(nDifficulty_);
  vChain_.push_back(bNew);
}


Block Blockchain::GetLastBlock_() const
{
  return vChain_.back();
}
