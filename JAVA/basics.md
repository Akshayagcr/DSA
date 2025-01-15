# 1. Methods

## Designing methods

public final void nap(int minutes) throws InterruptedException {};

1. **Method declaration** = 1: Access modifier + 2: Optional specifier + 3: return type + 4: method name + 5: parameter list + 6: exception


    1. Access modifier      : public
    2. Optional specifier   : final 
    3. return type          : void 
    4. method name          : nap
    5. parameter list       : int minutes
    6. exception            : InterruptedException

2. **Method signature** = method name + parameter list(Types)
    1. method signature     : nap(int minutes)


### Access modifiers

1. private: Within same class
2. package: Within same package
3. protected: Withing same package and in subclassess in other packages
4. private : everywhere

### Optional Sepcifier

1. static
2. abstract
3. final
4. default
5. synchronized


## Declaring Local and Instance variables

1. Local variables
    - Local variables are defined inside methods.
        - All refrences defined inside methods are deleated after the method ends.
    - We can only apply **final** optional specifier to local variables
    - final local variables need to assign valuses before use and once assigned we cannont reassign.
    - **Effective final variables** are the variables that are final irrespective of whether they are marked as final or not. 
        - To test if a variable is effective final or not just mark the variable as final if the code works then the variable is effective final.
        - Local classess and **lambdas** can only access effective final variables.

2. Instance variables


## Working with Varargs

## Accessing statuc data

## Overloading Methods







*******************************************************************************************************

Method signature = method name + parameter list (* Does not include return type or access modifier)






































# 2. Class Design
# 3. Beyond Classes