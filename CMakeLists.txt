cmake_minimum_required(VERSION 3.5.0)
project(sedg14 VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_executable(sedg14 main.c 
    "Snippets/00. includes/array/array.c"
    "Snippets/00. includes/node DLL/nodeDLL.c"
    "Snippets/00. includes/node/node.c"
    "Snippets/00. includes/tree node/treeNode.c"
    "Snippets/00. includes/parse tree/parseTree.c"
    "Snippets/00. includes/mass suicide/massSuicide.c"
    "Snippets/00. includes/postfix/postfix.c"
    "Snippets/00. includes/point/point.c"

    "Snippets/00. includes/recurrences/halfInput.c"
    "Snippets/00. includes/recurrences/largestLog.c"

    "Snippets/01. gcd/01. gcd.c"
    "Snippets/03. fraction/03. fraction.c"
    "Snippets/04. convert/04. convert.c"
    "Snippets/05. binary/05. binary.c"
    "Snippets/06. greatest ints/06. greatestInts.c"
    "Snippets/08. sieve/08. sieve.c"

    "Snippets/09. list/09. list.c"
    "Snippets/09. list/09. listDL.c"

    "Snippets/10. parray/10. parray.c"

    "Snippets/12. stack/12. stackLL.c"
    "Snippets/12. stack/12. stackArray.c"
    "Snippets/12. stack/12. stackPA.c"

    "Snippets/13. queue/13. queueArray.c"
    "Snippets/13. queue/13. queueLL.c"

    "Snippets/14. 2d/14. 2d.c"
    "Snippets/18. tree traversal/18. treeTraversal.c"
    "Snippets/19. fibonacci/19. fibonacci.c"
    "Snippets/20. ruler/20. ruler.c"
    "Snippets/21. fractal/21. fractal.c"

    "Snippets/22. recursion removal/22. recursionRemovalPreOrder.c"
    "Snippets/22. recursion removal/22. recursionRemovalInOrder.c"
    "Snippets/22. recursion removal/22. recursionRemovalPostOrder.c"

    "Snippets/23. sort/23. sort.c"
    "Snippets/23. sort/23. sort3.c"
    "Snippets/23. sort/23. insSort.c"
)

target_link_libraries(sedg14 m) # Link libmath

#target_compile_options(sedg14 PRIVATE -Wall -Wextra)
target_compile_options(sedg14 PRIVATE -g3)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
