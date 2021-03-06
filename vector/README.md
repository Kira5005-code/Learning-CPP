## Задание
Реализовать шаблонный класс `my_vector` со строгими гарантиями исключений.
Можно считать, что для шаблонного типового параметра `T` выполняются следующие требования:

* [CopyConstructible](https://en.cppreference.com/w/cpp/named_req/CopyConstructible).
* [Destructible](https://en.cppreference.com/w/cpp/named_req/Destructible).
* Конструктор перемещения и оператор перемещающего присваивания `T` не бросают исключений.
* Все операции над `T` предоставляют базовую гарантию исключений.

Обратите внимание, что `T` может быть не [DefaultConstructible](https://en.cppreference.com/w/cpp/named_req/DefaultConstructible),
из-за чего нельзя писать `new T[]` в общем случае.

Также требуется:

* Перегрузить `operator<<` для вывода в `ostream` всех элементов `my_vector`.
* Реализовать класс `Product`, демонстрирующий минимальные требования к элементу `my_vector`,
  а также перегружающий `operator<<` для вывода.
* Реализовать шаблонные автоматические тесты `my_vector` и запустить их для `int` и `Product`.

Все операции:

* Работают по аналогии с `std::vector`, если в задании не сказано иное
* Предоставляют хотя бы строгую гарантию исключений, в том числе по отношению к `capacity()` и адресам элементов `my_vector`.
* По возможности перемещают элементы, если это можно сделать без нарушений гарантий исключений.
* Выполняют как можно меньше операций с элементами:
  * Не создают лишние элементы.
  * Не создают копии элементов, когда можно обойтись перемещением (без нарушения гарантий).
  * Не делают явно лишних перемещений (например, несколько перемещений между временными объектами).

### Класс `Product`
Интерфейс класса `Product` задан в `main.cpp`, его необходимо доработать,
чтобы он соответствовал *минимальным* требованиям `my_vector`.
При этом запрещается использовать стандартные контейнеры из `STL`,
в том числе `unique_ptr`.

Формат `operator<<` для `Product`: `<name> <quantity> <price>` (поля разделены ровно одним пробелом,
завершающего перевода строки нет).

### Консольное приложение
В `main.cpp` должна быть реализована шаблонная функция `test_my_vector`,
которая автоматически тестирует все методы класса `my_vector` для заданного типа.
Эта функция вызывается в `main` для `int` и нового типа `Product`.

Также должна быть реализована шаблонная функция `test_my_vector_default_constructible`,
которая тестирует методы класса `my_vector`, включающиеся только для `DefaultConstructible` типов.
Она вызывается в `main` для `int`.

