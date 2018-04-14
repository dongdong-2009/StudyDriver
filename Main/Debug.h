#ifndef _Debug_h_
#define _Debug_h_

/*
 */
ostream& DgbClearStream(char const*, uint32_t);
ostream& DgbOStream(char const*, uint32_t);
ostream& ErrOStream(char const*, uint32_t);

#define dbgcstrm DgbClearStream(__func__, __LINE__)
#define dbgstrm DgbOStream(__func__, __LINE__)
#define errstrm ErrOStream(__func__, __LINE__)

#define DbgExpandVar(v, type) #v << " = " << (type)v

class DebugFlag
{
public:
    DebugFlag();

    bool GetState(string const& funcName);
    void SetState(string const& funcName, bool isDebug);

private:
    static map<string, bool> flags;
};

#endif /* _Debug_h_ */
