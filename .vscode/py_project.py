# ипортирование библиотек
from manim import *
from math import *
# не умееет строить тригонометрические функции и функции, содержащие корень четной степени, и деление
from tkinter import *
from tkinter.ttk import Combobox
import sympy as sym


# zero приравнивает выражение, стоящее в знаменателе, к 0 и находит его корни
def zero(s):
    x = sym.Symbol('x')
    zn = list(map(str, sym.solve(s, x)))  # f(x)=0
    z = []
    for i in zn:
        st = i
        if "I" not in st:
            z.append(float(eval(st)))
    return z


# функция D1 устанавливает область определения функции, содержащей деление или степень с отрицательным показателем, в рассматриваемом интервале [х min, x max] 
def D1(z, x1, x2):  # z-список корней выражения, стоящего в знаменателе, x1-x min, x2-x min
    x_min = x1
    x_max = x2
    ans = []
    if len(z) != 0:
        z = sorted(z)
        ans.append([x_min, z[0] - 0.0799])
        for i in range(1, len(z)):
            ans.append([z[i - 1] + 0.0799, z[i] - 0.0799])
        ans.append([z[-1] + 0.0799, x_max])
    else:
        ans.append([x_min, x_max])
    return ans


# D устанавливает область определения функции, содержащей корень четной степени, в рассматриваемом интервале [х min, x max] 
def D(s, x1, x2):  # s-выражение под корнем, x1-x min, x2-x min
    x = sym.Symbol('x')
    d = str(sym.solve(s))
    print(d)
    if "|" in d:
        d = d.split(") | (")
        d[0] = d[0][1:]
        d[-1] = d[-1][:len(d[-1]) - 1]
    else:
        d = [d]
    ans = []
    for i in d:
        st = i.split(" & ")
        val_min = x1
        val_max = x2
        for j in st:
            if ("x <=" in j):
                elem1 = j[(j.find("=") + 2):len(j) - 1]
                val_max = eval(elem1) - 0.001
            if ("<= x" in j):
                elem2 = j[1:(j.find("=") - 2)]
                val_min = eval(elem2) + 0.001
        ans.append([val_min, val_max])
    return ans


# event проверяет функцию, содержащую модуль, на иной способ построения с помощью интервалов(без преобразований). Пример: y=|x-1|+|x**2-4|
def event(d, a):
    for i in a:
        for j in a:
            if i > d[j]:
                return True
    return False


# function возвращает список с последовательностью преобразований функции и индексы скобок, включающие в себя выражение с x под корнем или в знаменателе
def function(s):  # s - введенная строка f(x)
    A = []
    ind_sqrt = []
    ind_del = []
    k = s.count("abs")
    if (("log" in s) or ("tg" in s) or ("ctg" in s) or ("arcsin" in s) or ("arccos" in s)) or (
            ("abs" in s) and ("/" in s)):
        A = []
    elif (("abs" in s) or ("/" in s) or ("sqrt" in s) or ("pow" in s)):
        d = {}
        a = []
        b = []
        for i in range(len(s)):
            if s[i] == "(":
                if s[i - 1] == "s":
                    a.append(i)
                else:
                    b.append(i)
            elif s[i] == ")":
                if a != [] and (b == [] or b[-1] < a[-1]):
                    d[a[-1]] = i
                    a.pop()
                else:
                    if s[b[-1] - 1] == "/" and "x" in s[b[-1]:i]:
                        ind_del.append([b[-1] + 1, i])
                    elif s[b[-1] - 4:b[-1]] == "sqrt" and "x" in s[b[-1]:i]:
                        ind_sqrt.append([b[-1] + 1, i])
                    elif s[b[-1] - 3:b[-1]] == "pow" and "x" in s[b[-1]:i]:
                        z = s.find(",")
                        exp = s[b[-1] + 1:i]
                        exp = exp[exp.find(",") + 2:]
                        if (eval(exp) < 0):
                            ind_del.append([b[-1] + 1, z])
                        elif (exp.find("/") and int(exp[exp.find("/") + 1:]) % 2 == 0):
                            ind_sqrt.append([b[-1] + 1, z])

                    b.pop()
        key = sorted(d)
        if (s.count("x") > 1 and k > 1 and event(d, key) == True) or (
                (len(ind_del) > 0 and len(ind_sqrt) == 0) or (len(ind_del) == 0 and len(ind_sqrt) > 0)):
            A.append(s)
        elif len(ind_del) + len(ind_sqrt) == 0:
            count = s.count("x")
            s1 = s
            start = 0
            if s.count('x') != 1:
                for l in range(len(key)):
                    string = s[key[l]:d[key[l]] + 1]
                    if string.count("x") == count:
                        s1 = s[key[l] - 3:d[key[l]] + 1]
                        start = l
            if s1 == s:
                A.append(s)
                key1 = key
                j, i = key1[0], d[key1[0]]
                for c1 in range(len(key1)):
                    A.append(A[-1][:j - 3] + A[-1][j + 1:i] + A[-1][i + 1:])
                    if len(key1) > c1 + 1:
                        for c2 in range(c1 + 1, len(key1)):
                            if key1[c2] < i:
                                key1[c2] -= 4
                            else:
                                key1[c2] -= 5
                        i, j = key1[c1 + 1] + 2, key1[c1 + 1]
                A = A[::-1]
            else:
                A = function(s1)[2]
                a1 = [s]
                key1 = key[:start]
                j, i = key1[0], d[key1[0]]
                for c1 in range(len(key1)):
                    a1.append(a1[-1][:j - 3] + a1[-1][j + 1:i] + a1[-1][i + 1:])
                    if len(key1) > c1 + 1:
                        for c2 in range(c1 + 1, len(key1)):
                            if key1[c2] < i:
                                key1[c2] -= 4
                            else:
                                key1[c2] -= 5
                        i, j = key1[c1 + 1] + 2, key1[c1 + 1]
                a1 = a1[::-1]
                for m in a1:
                    A.append(m)
    else:
        A.append(s)
    return ind_sqrt, ind_del, A


# построение экранной клавиатуры
class Keypad(Frame):
    cells = [
        ["0", "1", "2", "/", "("],
        ["3", "4", "5", "*", ")"],
        ["6", "7", "8", "-", "x"],
        ["9", ".", ",", "+"]]

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        self.target = None
        self.memory = ''

        for y, row in enumerate(self.cells):
            for x, item in enumerate(row):
                b = Button(self, text=item, command=lambda text=item: self.append(text))
                b.grid(row=y, column=x)
        sqrt_ = Button(self, text='√ (sqrt(x))', command=self.append_sqrt)
        sqrt_.grid(row=0, column=10)
        pow_ = Button(self, text='x^a (pow(x, a))', command=self.append_pow)
        pow_.grid(row=1, column=10)
        mod_ = Button(self, text='|a| (abs(x))', command=self.append_mod)
        mod_.grid(row=2, column=10)
        x = Button(self, text='⌫', command=self.backspace)
        x.grid(row=0, column=11)

        x = Button(self, text='AC', command=self.clear)
        x.grid(row=1, column=11)

        x = Button(self, text='Скрыть', command=self.hide)
        x.grid(row=10, column=0, columnspan=11, sticky=E)

    def get(self):
        if self.target:
            return self.target.get()

    def append(self, text):
        if self.target:
            self.target.insert('end', text)

    def append_sqrt(self):
        if self.target:
            self.target.insert('end', "sqrt")

    def append_pow(self):
        if self.target:
            self.target.insert('end', "pow")

    def append_mod(self):
        if self.target:
            self.target.insert('end', "abs")

    def clear(self):
        if self.target:
            self.target.delete(0, 'end')

    def backspace(self):
        if self.target:
            text = self.get()
            text = text[:-1]
            self.clear()
            self.append(text)

    def show(self, entry):
        self.target = entry
        self.place(relx=0.5, rely=0.5, anchor='c')

    def hide(self):
        self.target = None
        self.place_forget()


# создание интерфейса приложения
def tk():
    a = []

    def clicked():  # получение всех введенных параметров построения графика: f(x), цвет линий осей графика, интервал, деление шкалы
        if txt.get() and min_x.get() and max_x.get() and div_x.get() and div_y.get() and min_y.get() and max_y.get():
            s = txt.get()
            ax_c = combo1.get()
            gr_c = combo2.get()
            mn_x = float(min_x.get())
            mx_x = float(max_x.get())
            mn_y = float(min_y.get())
            mx_y = float(max_y.get())
            dif_x1 = float(div_x.get())
            dif_y1 = float(div_y.get())
            window.destroy()
            a.append(s)
            a.append(ax_c)
            a.append(gr_c)
            a.append(mn_x)
            a.append(mn_y)
            a.append(mx_x)
            a.append(mx_y)
            a.append(dif_x1)
            a.append(dif_y1)

    window = Tk()
    window.title("Plotting")
    window.geometry('850x430')

    lbl = Label(window, text="y(x) = ", fg="white", font=('asinastra', 13))
    lbl.grid(column=0, row=0)
    txt = Entry(window, width=50, bg="black", fg="white")
    txt.grid(column=1, row=0)
    col = Label(window, text="ЦВЕТ ЛИНИЙ", font=('asinastra', 13))
    col.grid(column=0, row=1, sticky=W)
    keypad = Keypad(window)
    b1 = Button(window, text='Клавиатура', fg="black", command=lambda: keypad.show(txt))
    b1.grid(row=1, column=1, sticky=E)

    axes = Label(window, text="Система координат: ", fg="white")
    axes.grid(column=0, row=2)

    combo1 = Combobox(window)
    combo1['values'] = ("RED", "ORANGE", "YELLOW", "GREEN", "BLUE", "PINK", "PURPLE", "WHITE")
    combo1.current(4)  # установите вариант по умолчанию
    combo1.grid(column=0, row=3)

    graph = Label(window, text="График функции: ", fg="white")
    graph.grid(column=0, row=4)

    combo2 = Combobox(window)
    combo2['values'] = ("RED", "ORANGE", "YELLOW", "GREEN", "BLUE", "PINK", "PURPLE", "WHITE")
    combo2.current(4)  # установите вариант по умолчанию
    combo2.grid(column=0, row=5)

    interval = Label(window, text="ИНТЕРВАЛ", font=('asinastra', 13))
    interval.grid(column=0, row=6, sticky=W)

    x1 = Label(window, text="Ось x        [", fg="white")
    x1.grid(column=0, row=7, sticky=W)
    min_x = Entry(window, width=5)
    min_x.grid(column=0, row=7)
    x = Label(window, text=" , ", fg="white")
    x.place(x=135, y=175)
    max_x = Entry(window, width=5)
    max_x.grid(column=0, row=7, sticky=E)
    x2 = Label(window, text="]", fg="white")
    x2.place(x=210, y=181)

    y1 = Label(window, text="Ось y        [", fg="white")
    y1.grid(column=0, row=8, sticky=W)
    min_y = Entry(window, width=5)
    min_y.grid(column=0, row=8)
    y = Label(window, text=" , ", fg="white")
    y.place(x=135, y=203)
    max_y = Entry(window, width=5)
    max_y.grid(column=0, row=8, sticky=E)
    y2 = Label(window, text="]", fg="white")
    y2.place(x=210, y=209)

    span = Label(window, text="ШКАЛЫ ОСЕЙ КООРДИНАТ", fg="white")
    span.grid(column=0, row=10, sticky=W)
    division_x = Label(window, text="Деление оси x", fg="white")
    division_x.grid(column=0, row=11, sticky=W)
    div_x = Entry(window, width=5)
    div_x.grid(column=0, row=11, sticky=E)
    division_y = Label(window, text="Деление оси y", fg="white")
    division_y.grid(column=0, row=12, sticky=W)
    div_y = Entry(window, width=5)
    div_y.grid(column=0, row=12, sticky=E)

    btn = Button(window, text="Построить", font=('asinastra', 13), bg="white", fg="black", command=clicked)
    btn.grid(column=2, row=10)
    window.mainloop()
    return a


# построение осей координат и графика функции
class Graph(Scene):
    global A, a, ind_sqrt, ind_del, domain
    a = tk()
    ind_sqrt, ind_del, A = function(a[0])

    def construct(self):
        if len(A) == 0:
            print("Plotting не может решить эту задачу")
            return 0
        axes = Axes(x_range=[a[3], a[5], a[7]], y_range=[a[4], a[6], a[8]], x_length=9.5, y_length=5.6,
                    axis_config={"color": a[1], "include_numbers": True, "font_size": 24}, tips=False)
        x_label = axes.get_x_axis_label("x")
        y_label = axes.get_y_axis_label("y", buff=-1)
        axes_labels = VGroup(x_label, y_label)
        gr_c = "GREY"
        if len(A) == 1:
            gr_c = a[2]
        self.play(Create(axes))
        self.add(axes_labels)
        self.wait(1)
        if len(ind_del) > 0:
            list_zero = []
            for i in range(len(ind_del)):
                t = A[0][ind_del[i][0]:ind_del[i][1]]
                z = zero(t)
                for j in z:
                    list_zero.append(j)
            domain = D1(list_zero, a[3], a[5])
        elif len(ind_sqrt) > 0:
            list_sqrt = []
            for i in range(len(ind_sqrt)):
                t = A[0][ind_sqrt[i][0]:ind_sqrt[i][1]] + ">=0"
                list_sqrt.append(t)
            domain = D(list_sqrt, a[3], a[5])
        else:
            domain = [[a[3], a[5]]]
        func_graph = VGroup()
        for j in domain:
            gr = axes.plot(lambda x: eval(A[0]), color=gr_c, x_range=j)
            func_graph.add(gr)
        self.play(Create(func_graph))
        graph_lab = Title("y = " + A[0], include_underline=False, font_size=40)
        self.play(Write(graph_lab))
        n = len(A) - 1
        l = len(A)
        while n > 1:
            self.wait(2)
            func_ngraph = axes.plot(lambda x: eval(A[l - n]), color=gr_c)
            graph_lab2 = Title("y = " + A[l - n], include_underline=False, font_size=40)
            self.play(Transform(func_graph, func_ngraph))
            self.play(Uncreate(graph_lab))
            self.play(Write(graph_lab2))
            self.wait(2)
            if n - 1 == 1:
                gr_c = a[2]
            func_graph = axes.plot(lambda x: eval(A[l - n + 1]), color=gr_c)
            graph_lab = Title("y = " + A[l - n + 1], include_underline=False, font_size=40)
            self.play(Transform(func_ngraph, func_graph))
            self.play(Uncreate(graph_lab2))
            self.play(Write(graph_lab))
            n -= 2
        else:
            gr_c = a[2]
            if n == 1:
                self.wait(2)
                func_ngraph = axes.plot(lambda x: eval(A[l - n]), color=gr_c)
                graph_lab2 = Title("y = " + A[l - n], include_underline=False, font_size=40)
                self.play(Transform(func_graph, func_ngraph))
                self.play(Uncreate(graph_lab))
                self.play(Write(graph_lab2))

        self.wait(10)
