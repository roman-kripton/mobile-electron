#include <node.h>
#include <node_buffer.h>

#include "focus.h"

namespace bindings
{
    using v8::Boolean;
    using v8::Exception;
    using v8::FunctionCallbackInfo;
    using v8::HandleScope;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;
    using v8::NewStringType;

    using focus::FocusWindow;

    void FocusWindowExport(const FunctionCallbackInfo<Value>& args)
    {
        Isolate* isolate = Isolate::GetCurrent();
        HandleScope scope(isolate);

        if (args.Length() < 1)
        {
            Local<String> message = String::NewFromUtf8(isolate,
                "Expected one argument", NewStringType::kNormal).ToLocalChecked();
            isolate->ThrowException(Exception::TypeError(message));
            return;
        }

        if (!args[0]->IsObject())
        {
            Local<String> message = String::NewFromUtf8(isolate,
                "Expected first argument to be a window handle buffer",
                NewStringType::kNormal).ToLocalChecked();
            isolate->ThrowException(Exception::TypeError(message));
            return;
        }

        auto context = isolate->GetCurrentContext();
        unsigned char *windowHandleBuffer =
            (unsigned char *)node::Buffer::Data(args[0]->ToObject(context).ToLocalChecked());

        FocusWindow(windowHandleBuffer);
    }

    void Initialize(Local<Object> exports)
    {
        NODE_SET_METHOD(exports, "focusWindow", FocusWindowExport);
    }
}  // namespace bindings

NODE_MODULE(module_name, bindings::Initialize)
