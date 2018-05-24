*Куценок Леонид, группа 6303, лабораторная работа 6 "Алгоритм Ахо-Корасик"*
# Сборка
Выполните команду `cmake .` в директории исходный файлов для создания необходимых конфигурационных файлов, которые потребуются при последующей сборке
## Сборка всех исполняемых файлов
`cmake --build "" --target all`
## Сборка программ, реализующих алгоритмы
 - Ахо-Корасик
 `cmake --build "" --target aho_corasick`
  - Ахо-Корасик с джокером
 `cmake --build "" --target joker`
## Сборка программ, тестирующих алгоритмы
 - Ахо-Корасик
 `cmake --build "" --target aho_corasick_test`
  - Ахо-Корасик с джокером
 `cmake --build "" --target joker_test`
# Запуск программ
## Алгоритмы
> Программы ожидают ввод, аналогичный вводу на Stepik
 - Ахо-Корасик
 `./aho_corasick`
  - Ахо-Корасик с джокером
 `./joker`
## Тестирование
 - Ахо-Корасик
 `./aho_corasick_test`
  - Ахо-Корасик с джокером
 `./joker_test`