# cppsanitiser

c++filt Qt sanitiser

This is a simple helper function for Qt/C++ template experimentation.

You can use typeid(type_or_object).name() to get a 'finger print' of the type.

However, it doesn't read like much.

Pass it into 'sanitise' and you'll see something mildly nicely formatted.

```cpp
    QTextStream _out(stdout);
    _out << sanitise(typeid(type_list<int,float,type_list<int,bool,void>>).name());
```

prints out...

```cpp
type_list<
    int,
    float,
    type_list<
        int,
        bool,
        void
    >
```

Now you don't have to rely of failing compilation and your crazy metaprogramming
experiments can yield many results!

PREREQS

* Make sure that c++filt is present and accessible to you application

matthew@kuiash.com
