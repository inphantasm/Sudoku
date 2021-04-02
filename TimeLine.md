## 2021/04/02

- 基本内容
  - Sudoku类：
    - 将matrix原有数据结构更改为square(==vector\<vector\<char\>\>)
  - Sudoku_Gen类：
    - square GenFinal_Violent，生成一个填满的9*9数独终局来满足需求，暂时意义不明，考虑可能用数独终局挖空来产生一个数独。

## 2021/04/01

- 建立项目
  - 根据需求建立了Sudoku、Sudoku_Generator和Sudoku_Solver。

- 基本内容
  - Sudoku类：
    - char matrix\[9]\[9]，用于存储数独
    - int blank，用于记录数独目前“空白”('#')的个数。