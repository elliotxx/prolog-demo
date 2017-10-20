/*  $Id$

    Part of SWI-Prolog

    This example code is in the public domain
*/


#include "SWI-cpp.h"
#include <iostream>
using namespace std;

/* Usage:

   likes			prints who likes what
   likes x			prints what is liked by x
   likes x y			Test whether x likes y
   likes -happy			See who is happy

   Compile using:

   plld -o likes -ld g++ -goal true likes.cpp likes.pl
*/

int
body(int argc, char **argv)
{ if ( argc == 1 )
  { if ( strcmp(argv[0], "-sanjiaolian") == 0 )
    { PlTermv av(3);			/* likes - happy */

      cout << "Sanjiaolian people:" << endl;
      PlQuery q("sanjiaolian", av);
      while( q.next_solution() ){
	cout << "\t" << (char *)av[0] << endl;
	cout << "\t" << (char *)av[1] << endl;
	cout << "\t" << (char *)av[2] << endl;
      }
    } else
    { PlTermv av(2);

      cout << argv[0] << " love:" << endl;
      av[0] = argv[0];
      PlQuery q("love", av);
      while( q.next_solution() )
	cout << "\t" << (char *)av[1] << endl;
    }
  } else if ( argc == 2 )
  { PlTermv av(2);

    av[0] = argv[0];
    av[1] = argv[1];
    if ( PlCall("love", av) )
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  } else
    cout << "Usage: love x [y] or love -sanjiaolian" << endl;

  return 0;
}


int
main(int argc, char **argv)
{ PlEngine e(argv[0]);

  try
  { return body(argc-1, argv+1);
  } catch ( PlException &ex )
  { cerr << (char *) ex << endl;
    exit(1);
  }
}


