flex lexer.l
gcc -o lexer lex.yy.c -lfl
echo 'x = 10; y = 20; z = (x + y);' | ./lexer > lexer_output.txt