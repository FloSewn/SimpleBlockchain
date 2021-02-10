#pragma once

#include <cstdint>
#include <vector>
#include "Block.h"


class Blockchain
{
public:
  Blockchain();

  void AddBlock(Block bNew);

private:
  uint32_t            nDifficulty_;
  std::vector<Block>  vChain_;

  Block GetLastBlock_() const;
};

