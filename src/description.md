# S21_SmartCalc

Данный проект - осуществление инженерного калькулятора в исполнении обратной польской нотации. Калькулятор имеет функцию построения графика, калькулятор кредитный и депозитный(по аналогии с сайтом https://calcus.ru/kreditnyj-kalkulyator и https://calcus.ru/kalkulyator-vkladov соотвественно).

При использовании калькулятора представлены следующие операции:
1. Сумма
2. Разность
3. Умножение
4. Деление
5. Остаток от деления
6. Возведение в степень
7. Корень квадратный
8. Синус(арксинус)
9. Косинус(арккосинус)
10. Тангенс(арктангенс)
11. Натуральный логарифм
12. Десятичный логарифм
13. Скобки

Тип сборки: qmake

Сборка приложения:

Запуск тестирования:

Покрытие тестами: make 

## Инструкция по эксплуатации:
### 1.Расчет
Чтобы выполнить расчет, введите выражение, обращая внимание на скобки и операции: все знаки надо указывать явно, как и скобки(скобочная логика, количество). Некорректный ввод данных выведет ERROR на поле ввода.
### 2.Построение графика
Чтобы построить график, необходимо ввесли математическое выражение с наличием переменной, но оставить поле принимаемую переменной числа пустой(в ином случае графиком всегда будет являться прямая). Нажать на кнопку вызова графика, указать интересующий вас интервал на координатной плоскости и нажать на кнопку PLOT(если ввести интервалы некорректно, выйдет надпись ERROR).
### 3.Кредитный калькулятор
Чтобы воспользоваться данной функцией калькулятора, необходимо нажать на соответствующую кнопку в главном окне, после чего появится поле ввода данных. На ваш выбор две реализации калькулятора: кредитный и депозитный. При некорректном вводе данных выйдет ошибка ERROR.
### 4. Депозитный калькулятор
Чтобы воспользоваться данной функцией калькулятора, необходимо нажать на соответствующую кнопку в главном окне, после чего появится поле ввода данных. Вводите данные внимательно. При некорректном вводе данных выйдет ошибка ERROR.