// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
//
// Copyright (c) 2011-2017 Crypto-Composite Ltd.
// Distributed under the MIT software license, see the accompanying
//


//////////////////////////////////
// DN Node scaffolding.
//////////////////////////////////

#include <nan.h>

#include <vector>
#include <string>

std::string AddonMain(int argc, char** argv);

int buildParamArrayForCLIInterface(Nan::NAN_METHOD_ARGS_TYPE info, std::vector<std::string> & vec)
{
   int numArgs = info.Length();
   for (int i = 0; i < numArgs; ++i)
   {
      auto infoValue = info[i]->ToString();
      v8::String::Utf8Value param1(infoValue);
      std::string param = std::string(*param1);
      vec.push_back(param);

printf("buildParamArrayForCLIInterface(): %s\n", param.c_str());
   }
   return numArgs;
}


/*
*******************************************************************
** DN.Main addon method implementing bitcoing-cli functionality.
*******************************************************************
*/

const std::size_t NCLIPARAMS = 5;
const std::size_t BUFSIZE = 128;

NAN_METHOD(BitcoinCli) {  
  
  if (!info[0]->IsString()) {
    Nan::ThrowError("Argument must be a string");
    return;
  }


  std::vector<std::string> vec;
  buildParamArrayForCLIInterface(info, vec);
  
  char* argv[NCLIPARAMS] = {0};
  for (int i = 0; i < NCLIPARAMS; ++i)
  {
    argv[i] = new char[BUFSIZE];
  }
  

  strcpy(argv[0], "exeProxy");
  strcpy(argv[1], vec[0].c_str());
  if (vec.size() == 2)
  {
    strcpy(argv[2], vec[1].c_str());
  }

  
/*
  printf("BitcoinCli() 1 %s\n", argv[0]);
  printf("BitcoinCli() 2 %s\n", argv[1]);
  printf("BitcoinCli() 3 %s\n", argv[2]);
*/

  auto retVal = AddonMain(vec.size()+1, (char**)argv);
  auto message = Nan::New<v8::String>(retVal.c_str()).ToLocalChecked();
  info.GetReturnValue().Set(message);

  for (int i = 0; i < NCLIPARAMS; ++i)
  {
    delete [] argv[i];
  }

}

/*
************************
** More Nan boilerplate.
************************
*/

NAN_MODULE_INIT(Initialize) {  
  NAN_EXPORT(target, BitcoinCli);
}

NODE_MODULE(addon, Initialize)  

// End DN.





