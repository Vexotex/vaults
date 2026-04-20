Quelle: Teil 7 – Implementierung, Simulation, Anwendung

## Problemstellung
Lösung von $\dot{\mathbf{x}} = f(\mathbf{x}, t)$ numerisch, d.h. schrittweise in der Zeit.

## Euler-Verfahren
- **Vorwärts-Euler (explizit)**: $\mathbf{x}_{k+1} = \mathbf{x}_k + T_0 \cdot f(\mathbf{x}_k, t_k)$
  - Einfach, aber instabil bei großer Schrittweite
- **Rückwärts-Euler (implizit)**: löst $\mathbf{x}_{k+1}$ aus $\mathbf{x}_{k+1} = \mathbf{x}_k + T_0 \cdot f(\mathbf{x}_{k+1}, t_{k+1})$
  - Stabiler, aufwendiger

## Runge-Kutta 4. Ordnung (RK4)
- Genauestes klassisches Verfahren
- 4 Funktionsauswertungen pro Schritt
- Fehler: $\mathcal{O}(T_0^4)$

## Schrittweitensteuerung
- Adaptive Schrittweite: Fehler schätzen und $T_0$ anpassen
- In Matlab/Simulink: ode45 (RK4/5 adaptiv), ode23, ode15s (steif)
