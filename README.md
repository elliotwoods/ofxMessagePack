ofxMessagePack
==============

Implementation of MessagePack for openFrameworks (based on msgpack-c)

Usage
-----

If you want to save something to a file (e.g. a vector of something), then use:

```cpp
ofxMessagePack::Packer packer;
packer << myObjectThatIWantToPack;
packer.save("filename.bin");
```

If you want to load something from a file, then use:

```cpp
ofxMessagePack::Unpacker unpacker;
unpacker.load("filename.bin");
unpacker >> myObjectThatIWantToPack;
```

If you don't want to use files (e.g. you're sending via network), then you can use:

```cpp
auto buffer = ofxMessagePack::Packer::getBuffer();
ofxMessagePack::Unpacker::setBuffer(buffer);
```

If you want to use MessagePack with custom data types (e.g. your own classes), then you need to add a line to your class definition, e.g.:

```cpp
class MyPoint : public ofVec2f {
public:
  MSGPACK_DEFINE(x, y)
};
```

Notice how the fields `x` and `y` are explicitly declared to MessagePack.

Generally MessagePack can natively serialise/deserialise the usual types (`int`, `double`, `bool`, `string`, etc) and can also handle containers (`vector`, `map`, etc).

Note
----

There is an existing addon for MessagePack at https://github.com/hiroyuki/ofxMessagePack (from which I got the osx libs). That addon works a little differently than this one, so make sure to check that one out also and see which one you prefer.
