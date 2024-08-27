### Techniques for Passing STL Containers in Competitive Programming

| **Method**                          | **When to Use**                                                                 | **Why It's Optimal**                                         |
|-------------------------------------|--------------------------------------------------------------------------------|-------------------------------------------------------------|
| **Pass by Reference (`T&`)**        | When you need to modify the container in the function.                          | No copy overhead, modifies the container in place.          |
| **Pass by Const Reference (`const T&`)** | When you only need to **read** the container and **don’t modify** it.          | Avoids copying, ensures the container isn't modified.       |
| **Pass by Value with Move (`std::move`)** | When you want to **transfer ownership** of the container to the function.      | Avoids copying for large containers, especially with move semantics. |
| **Return by Value (RVO/NRVO)**      | When returning a container from a function.                                     | Modern compilers will apply **copy elision** to avoid copying. |
