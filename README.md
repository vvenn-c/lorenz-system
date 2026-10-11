
---
# Forward Euler:

we have an ODE in the form of $\frac{dy}{dx} = f\Bigl(y(x)\Bigl)$
given the initial condition $y(x_{0}) = y_{0}$

by definition of derivate,
$$
\begin{align}
\frac{dy}{dx} &= f\Bigl(y(x)\Bigl) \\
\lim_{h \to 0} \left[\frac{y(x + h) - y(x)}{h}\right] &= f\Bigl(y(x)\Bigl) \\
\end{align}
$$
we approximate $h$ as $\Delta x$ :
$$
\begin{align}
\frac{y(x + \Delta x) - y(x)}{\Delta x} & \approx f\Bigl(y(x)\Bigl) \\
y(x + \Delta x) - y(x) & \approx f\Bigl(y(x)\Bigl) \cdot \Delta x \\
y(x + \Delta x) & \approx y(x) + f\Bigl(y(x)\Bigl) & \dots (1) \\
\end{align}
$$
$$
\begin{align}
\text{let } x_{n} &= x_{0} + n \Delta x & \implies x_{n+1} &= x_{n} + \Delta x \\
y_{n} &= y(x_{n}) & \implies y_{n+1} &= y(x_{n+1}) \\
\end{align}
$$
at $x = x_{0}$ for eq(1):
$$
\begin{align}
y(x_{0} + \Delta x) &= y(x_{0}) + f\Bigl(y(x_{0})\Bigl) \cdot \Delta x \\
y(x_{1}) &= y(x_{0}) + f\Bigl(y(x_{0})\Bigl) \cdot \Delta x \\
y_{1} &= y_{0} + f(y_{0}) \cdot \Delta x & \dots (2) \\
\end{align}
$$
at $x = x_{1}$ for eq(1):
$$
\begin{align}
y(x_{1} + \Delta x) &= y(x_{1}) + f\Bigl(y(x_{1})\Bigl) \cdot \Delta x \\
y_{2} &= y_{1} + f(y_{1}) \cdot \Delta x & \dots (3)
\end{align}
$$
from eq(2) and eq(3), we get the general form:
$$
\fbox{$y_{n+1} = y_{n} + f(y_{n}) \cdot \Delta x$}
$$
---
# Applying Euler's Method to the Laws of Motion:

we have a system of differential equations:
$$
\begin{align}
\frac{dp}{dt} = v(t) && \frac{d^2p}{dt^2} = \frac{dv}{dt} = a(t) 
\end{align} \\
$$
consider special case where $a = f\Bigl(v(t), p(t)\Bigl)$
given the initial conditions: $v(t_{0}) = v_{0}$ and $p(t_{0}) = p_{0}$

by definition of a derivative,
$$
\begin{align}
\frac{dp}{dt} &= v(t) & \frac{dv}{dt} &= a(t) \\
\lim_{h \to 0} \left[ \frac{p(t + h) - p(t)}{h}\right] &= v(t)
& \lim_{h \to 0} \left[ \frac{v(t + h) - v(t)}{h}\right] &= f\Bigl(v(t), p(t)\Bigl) \\
\end{align}
$$
we approximate h as $\Delta t$ :
$$
\begin{align}
\frac{p(t + \Delta t) - p(t)}{\Delta t} & \approx v(t)
& \frac{v(t + \Delta t) - v(t)}{\Delta t} & \approx f\Bigl(v(t), p(t)\Bigl) \\
p(t + \Delta t) - p(t) & \approx v(t) \cdot \Delta t
& v(t + \Delta t) - v(t) & \approx f\Bigl(v(t), p(t)\Bigl) \cdot \Delta t \\
p(t + \Delta t) & \approx p(t) + v(t) \cdot \Delta t
& v(t + \Delta t) & \approx v(t) + f\Bigl(v(t), p(t)\Bigl) \cdot \Delta t
\end{align}
$$
$$
\begin{align}
\text{let } t_{n} &= t_{0} + n \Delta t & \implies t_{n+1} &= t_{n} + \Delta t \\
p_{n} &= p(t_{n}) & \implies p_{n+1} &= p(t_{n+1}) \\
v_{n} &= v(t_{n}) & \implies v_{n+1} &= v(t_{n+1}) \\
\end{align}
$$
at $t = t_{0}$ :
$$
\begin{align}
p(t_{0} + \Delta t) &= p(t_{0}) + v(t_{0}) \cdot \Delta t
& v(t_{0} + \Delta t) &= v(t_{0}) + f\Bigl(v(t_{0}), p(t_{0})\Bigl) \cdot \Delta t \\
p(t_{1}) &= p(t_{0}) + v(t_{0}) \cdot \Delta t
& v(t_{1}) &= v(t_{0}) + f\Bigl(v(t_{0}), p(t_{0})\Bigl) \cdot \Delta t \\
p_{1} &= p_{0} + v_{0} \cdot \Delta t
& v_{1} &= v_{0} + f(v_{0}, p_{0}) \cdot \Delta t
\end{align}
$$
at $t = t_{1}$ :
$$
\begin{align}
p_{2} &= p_{1} + v_{1} \cdot \Delta t
& v_{2} &= v_{1} + f(v_{1}, p_{1}) \cdot \Delta t
\end{align}
$$
we get the general form:
$$
\begin{align}
\fbox{$p_{n+1} = p_{n} + v_{n} \cdot \Delta t$}
&& \fbox{$v_{n+1} = v_{n} + f(v_{n}, p_{n}) \cdot \Delta t$}
\end{align}
$$
---
# Runga-Kutta Method (RK4):

given an ODE in the form of $\frac{dy}{dx} = f\Bigl(y(x)\Bigl)$
with the initial condition $y(x_{0}) = y_{0}$

$$
\begin{align}
\text{let } x_{n} &= x_{0} + n \Delta x & \implies x_{n+1} &= x_{n} + \Delta x \\
y_{n} &= y(x_{n}) & \implies y_{n+1} &= y(x_{n+1}) \\
\end{align}
$$

using Euler's Method, we can calculate $y_{n+1}$ at a few points:
$$
\begin{align}
Y_{1} &= y_{n} + f(y_{n}) \cdot \Delta x \\
Y_{2} &= y_{n} + f\left( y_{n} + \frac{Y_{1}}{2} \right) \cdot \Delta x \\
Y_{3} &= y_{n} + f\left( y_{n} + \frac{Y_{2}}{2} \right) \cdot \Delta x \\
Y_{4} &= y_{n} + f(y_{n} + Y_{3}) \cdot \Delta x
\end{align}
$$
then we take a weighted average:
$$
\fbox{$y_{n+1} = \frac{1}{6} (Y_{1} + 2Y_{2} + 2Y_{3} + Y_{4})$}
$$
---
# Applying RK4 to the Lorenz System:

we have a system of differential equations:
$$
\begin{align}
\frac{dx}{dt} &= \sigma (y - x)
& \frac{dy}{dt} &= x(\rho - z) - y
& \frac{dz}{dt} &= xy - \beta z
\end{align}
$$
$$
\begin{align}
\sigma = 10 && \rho = 28 && \beta = \frac{8}{3}
\end{align}
$$
which are in the following forms respectively,
$$
\begin{align}
\frac{dx}{dt} &= f\Bigl(x(t), y(t)\Bigl)
& \frac{dy}{dt} &=  g\Bigl(x(t), y(t), z(t)\Bigl)
& \frac{dz}{dt} &= h\Bigl(x(t), y(t), z(t)\Bigl) \\
& \dots (1) && \dots (2) && \dots (3)
\end{align}
$$
with the initial conditions:
$$
\begin{align}
x(t_{0}) = x_{0} && y(t_{0}) = y_{0} && z(t_{0}) = z_{0} \\
\\
\end{align}
$$
$$
\begin{align}
\text{let } t_{n} &= t_{0} + n \Delta t & \implies t_{n+1} &= t_{n} + \Delta x \\
x_{n} &= x(t_{n}) & \implies x_{n+1} &= x(t_{n+1}) \\
y_{n} &= x(t_{n}) & \implies y_{n+1} &= y(t_{n+1}) \\
z_{n} &= z(t_{n}) & \implies z_{n+1} &= z(t_{n+1}) \\ \\
 \\

\end{align}
$$
$$
\begin{align}
X_{1} &= x_{n} + f(x_{n}, y_{n}) \cdot \Delta t \\
Y_{1} &= y_{n} + g(x_{n}, y_{n}, z_{n}) \cdot \Delta t \\
Z_{1} &= z_{n} + h(x_{n}, y_{n}, z_{n}) \cdot \Delta t \\
\\
X_{2} &= x_{n} + f\left( x_{n} + \frac{X_{1}}{2}, y_{n} + \frac{Y_{1}}{2} \right) \cdot \Delta t \\
Y_{2} &= y_{n} + g\left( x_{n} + \frac{X_{1}}{2}, y_{n} + \frac{Y_{1}}{2}, z_{n} + \frac{Z_{1}}{2} \right) \cdot \Delta t \\
Z_{2} &= z_{n} + h \left( x_{n} + \frac{X_{1}}{2}, y_{n} + \frac{Y_{1}}{2}, z_{n} + \frac{Z_{1}}{2} \right) \cdot \Delta t \\
\\
X_{3} &= x_{n} + f\left( x_{n} + \frac{X_{2}}{2}, y_{n} + \frac{Y_{2}}{2} \right) \cdot \Delta t \\
Y_{3} &= y_{n} + g\left( x_{n} + \frac{X_{2}}{2}, y_{n} + \frac{Y_{2}}{2}, z_{n} + \frac{Z_{2}}{2} \right) \cdot \Delta t \\
Z_{3} &= z_{n} + h \left( x_{n} + \frac{X_{2}}{2}, y_{n} + \frac{Y_{2}}{2}, z_{n} + \frac{Z_{2}}{2} \right) \cdot \Delta t \\
\\
X_{4} &= x_{n} + f(x_{n} + X_{3}, y_{n} + Y_{3}) \cdot \Delta t \\
Y_{4} &= y_{n} + g(x_{n} + X_{3}, y_{n} + Y_{3}, z_{n} + Z_{3}) \cdot \Delta t \\
Z_{4} &= z_{n} + h(x_{n} + X_{3}, y_{n} + Y_{3}, z_{n} + Z_{3}) \cdot \Delta t \\
\end{align}
$$
then we take the weighted average:
$$
\begin{align}
\Aboxed{x_{n+1} &= \frac{1}{6} (X_{1} + 2X_{2} + 2X_{3} + X_{4})}
\Aboxed{y_{n+1} &= \frac{1}{6} (Y_{1} + 2Y_{2} + 2Y_{3} + Y_{4})}
\Aboxed{z_{n+1} &= \frac{1}{6} (Z_{1} + 2Z_{2} + 2Z_{3} + Z_{4})}
\end{align}
$$
![[lorenz-system.mp4]]

---
