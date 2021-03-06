#include <nan.h>
#include "node-aes-ccm.h"
#include "node-aes-gcm.h"

using namespace v8;
using namespace node;

// Module init function

NAN_MODULE_INIT(InitAll) {
	Nan::Set(target, 
        Nan::New<String>("CcmEncrypt").ToLocalChecked(),
        Nan::GetFunction(Nan::New<FunctionTemplate>(ccm::Encrypt)).ToLocalChecked()
    );
	Nan::Set(target, 
        Nan::New<String>("CcmDecrypt").ToLocalChecked(),
        Nan::GetFunction(Nan::New<FunctionTemplate>(ccm::Decrypt)).ToLocalChecked()
    );

	Nan::Set(target, 
        Nan::New<String>("GcmEncrypt").ToLocalChecked(),
        Nan::GetFunction(Nan::New<FunctionTemplate>(gcm::Encrypt)).ToLocalChecked()
    );
	Nan::Set(target, 
        Nan::New<String>("GcmDecrypt").ToLocalChecked(),
        Nan::GetFunction(Nan::New<FunctionTemplate>(gcm::Decrypt)).ToLocalChecked()
    );
}

NODE_MODULE(node_aead_crypto, InitAll)