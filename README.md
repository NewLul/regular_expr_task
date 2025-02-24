
Задача: есть регулярное выражение в польской нотации и строка вида x^k, где x -- символ из алфавита. Нужно найти минимальное по длине слово из нашего языка, которое начинается на x^k.

В данном задании мы для каждого регулярного выражения подсчитываем две величины: 
- $prefix[i]$ - минимальная длина слова, которая начинается с $x^i$
- $whole[i]$ - принимает ли это регулярное выражение слово $x^i$ 

Как же склеивать два регулярных выражения?

- При сложении двух регулярных выражений для соответствующих величин выбирется наименьшее.
- При конкатенации регулярных выражений можно тривиально пересчитать необходимое.   
- При итерации Клини необходимо обозначить $prefix[0] = whole[0] = 0$. Дальше нужно перебрать всевозможные пары $whole[i]$ и $whole[j]$ и обновить $whole[i + j]$. В завершение нужно перебрать всевозможные пары $whole[i]$ и $prefix[j]$ и обновить через них $prefix[i + j]$ и все меньшие префиксы.

Итоговая асимптотика решения - $O(n + nk^3)$, где $n$ - длина регулярного выражения. 
Это действительно так, потому что первые две операции работают за $O(k^2)$, а третья за $O(k^3)$, давая итоговую асимптотику.
