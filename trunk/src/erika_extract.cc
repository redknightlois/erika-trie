#include <iostream>
#include <string>
#include "erika_trie.h"
using namespace std;
using namespace erika;

int main(int argc, char **argv) {
  if (argc < 2) {
    cerr << "USAGE: erika_extract <trie_name> < infile" << endl;
    return 0;
  }

  try {
    trie   t(argv[1]);
    string s;
    while (getline(cin, s)) {
      cout << "# " << s << endl;
      vector<value> v;
      t.extract(s.c_str(), v);
      vector<value>::const_iterator i = v.begin();
      vector<value>::const_iterator e = v.end();
      while (i != e) {
        cout << s.substr(i->begin(), i->end() - i->begin())
             << "\t" << i->begin() << "\t" << i->end() << endl;
        i++;
      }
    }
  } catch (const char *err) {
    cerr << err << endl;
    return 1;
  }
  return 0;
}
