# **W3DOJO FRACTION LIBRARY**

**W3 Dojo Fraction Library** is as the name suggest, a "Fraction Library". The library, to no ones supprise, adds support for fractions to any C++ programs/document that it is implimented in. The class overloads several operators, which include, but is not limited to: _'binary arithmatic opperators', 'assignment operator', 'arithmetic/assignment hybrid operators', 'comparison operators', 'equals/does-not-eaual operators', 'comparison operators', 'unary pre/post operators', 'ostream insertion operator' and the 'ifstream extersion operator'._

<br>

##### **The example bellow helps to demonstrate a few of the operators, and how the fraction class works.**

```
#include "${workingDir}/fraction.h"

using namespace cs_fraction;

int main(int &){
    Fraction frAlpha(1, 2),
             frBeta(1, 4);

    Fraction frGamma = frAlpha * frBeta;

    cout << "01| ALPHA + BETA = " << frAlpha + frBeta << endl;
    cout << "02| ALPHA - BETA = " << frAlpha - frBeta << endl;
    cout << "03| GAMMA = " << frGamma << endl;

    return;
}
```

<br>

##### **Add the 2 lines of code below to your file header when including the class in a C++ document.**

> 1. ##### _Include the relative path for the `"fraction.h"` file._
>
>     - _`#include "${workingDir}/fraction.h"`_
>
> 2. ##### _Add the `cs_namespace` to the document:_
>     - _`using namespace cs_fraction;`_

---

<br>

### TESTING THE FRACTION CLASS

---

##### Customizing the Class, is made easy whith the included test.

The makefile included with this library is for building a test. The test is very thorough, and is a near perfect compangian to the Fraction library if the developer using the library intends on adding to it. The test will ensure that everything, in its current state, is in working order, therefore; if something is added to the class, but has a negative effect during runtime everything that is part of the preexisting class, this test will likely catch it, and let you know. It a much needed tool, thats already been written, for implimenting a **_custom & robust_ "Fraction Class".**

<br>


---