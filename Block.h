#pragma once

#include <cstdint>
#include <iostream>


class Block
{
public:
  std::string sPrevHash;

  Block(uint32_t nIndexIn, const std::string &sDataIn);

  std::string GetHash();

  void MineBlock(uint32_t nDifficulty);

private:
  uint32_t        nIndex_;
  int64_t         nNonce_;
  std::string     sData_;
  std::string     sHash_;
  time_t          tTime_;

  std::string CalculateHash_() const;


};
