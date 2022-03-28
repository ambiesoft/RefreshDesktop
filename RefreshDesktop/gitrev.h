// DO NOT EDIT
// This file was created and will be overwritten by distSolution.py
// DO NOT EDIT

#ifndef GITREV_INCLUDED_
#define GITREV_INCLUDED_

#include <string>
#include <sstream>
namespace GITREV {
    static constexpr const wchar_t *hashes[][2] =  {

            {L"dummy1",L"0000000000000000000000000000000000000000"},
            {L"dummy2",L"0000000000000000000000000000000000000000"},

    };
    inline std::wstring GetHashMessage() {
        std::wstringstream message;
        for (auto&& s : hashes)
            message << s[0] << L"=" << s[1] << std::endl;
        return message.str();
    }
}  // namespace GITREV
#endif  // GITREV_INCLUDED_
