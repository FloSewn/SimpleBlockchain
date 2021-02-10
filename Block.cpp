#include <sstream>

#include "Block.h"
#include "sha256.h"


Block::Block(uint32_t nIndexIn, const std::string &sDataIn)
{
  nNonce_ = -1;
  tTime_  = time(nullptr);
}

std::string Block::GetHash()
{
  return sHash_;
}


void Block::MineBlock(uint32_t nDifficulty)
{
  char cstr[nDifficulty + 1] { '0' };
  
  for (uint32_t i = 0; i < nDifficulty; ++i)
  {
    cstr[i] = '0';
  }

  cstr[nDifficulty] = '\0';

  std::string str(cstr);

  /*
  std::string str = "";
  for (uint32_t i = 0; i < nDifficulty; i++)
    str += '0';
  str += '\0';
  */

  do
  {
    nNonce_++;
    sHash_ = CalculateHash_();
  } while( sHash_.substr(0, nDifficulty) != str );

  std::cout << "Block mined: " << sHash_ << std::endl;

}

inline std::string Block::CalculateHash_() const
{
  std::stringstream ss;
  ss << nIndex_ << tTime_ << sData_ << nNonce_ << sPrevHash;

  return sha256(ss.str());
}
