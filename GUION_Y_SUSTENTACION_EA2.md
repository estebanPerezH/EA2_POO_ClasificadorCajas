# GUION DE SUSTENTACIÓN EN VIDEO Y PARTICIPACIÓN EN EL FORO EA2
**Estudiante:** Jhoan Esteban Pérez Herrera  
**Asignatura:** Programación Orientada a Objetos – Ruta C++ (Ingeniería Mecatrónica)  
**Docente:** Juan Esteban Acevedo Carvajal  
**Institución:** IU Digital de Antioquia  

---

## 1. GUION PARA TU VIDEO DE SUSTENTACIÓN INDIVIDUAL (3:30 a 4:00 MINUTOS)

> **Instrucciones previas para grabar:**
> 1. Abre tu navegador en **OneCompiler** (o Visual Studio Code) con el archivo `clasificador_cajas.cpp`.
> 2. Ten lista la consola para ingresar los datos en vivo.
> 3. Comparte pantalla con tu cámara encendida en la esquina para identificarte.

---

### ⏱️ Minuto 0:00 - 0:40 | Saludo, Identificación y Contexto de la Solución
*(Hablando a la cámara, con energía y seguridad)*

> "Buenas tardes, profesor Juan Esteban y compañeros. Mi nombre es **Jhoan Esteban Pérez Herrera**, estudiante del programa de **Ingeniería Mecatrónica** en la IU Digital de Antioquia.
>
> Para esta Evidencia de Aprendizaje 2, doy continuidad al reto de la estación de empaque industrial que abordamos en la EA1: la clasificación automatizada de piezas en una fábrica de repuestos en el Valle de Aburrá.
>
> En la planta se requería un sistema que tome las medidas de las cajas que vienen por la línea transportadora, calcule su volumen en tiempo real y decida automáticamente si enviarlas a la **Banda A** (para cajas grandes mayores a 500 cm³) o a la **Banda B** (para cajas estándar menores o iguales a 500 cm³), procesando todo el lote del turno de forma continua."

---

### ⏱️ Minuto 0:40 - 1:50 | Explicación del Código y Lógica de Flujo
*(Muestra el editor de código con `clasificador_cajas.cpp`)*

> "Pasando al código que desarrollé en C++:
>
> 1. **Variables y Tipos de Datos:** Definí variables tipo `float` para las medidas físicas (`ancho`, `alto`, `profundidad` y `volumen`), variables enteras para los contadores (`totalCajas`, `cajasBandaA`, `cajasBandaB`) y un acumulador de `volumenTotal` para el balance del lote.
>
> 2. **Ciclo `do-while`:** Escogí un ciclo `do-while` porque en una línea de ensamble siempre debe procesarse al menos una primera pieza al arrancar el turno, y el ciclo debe continuar ejecutándose mientras el operario confirme con `continuar == 'S'`.
>
> 3. **Decisión 1 (Validación de Seguridad):** Lo primero que hace el algoritmo tras leer las medidas es validar con un `if`:
>    `if (ancho <= 0 || alto <= 0 || profundidad <= 0)`
>    Si un sensor falla o el operario tipea un valor negativo o cero, el sistema emite una alerta y **descarta la caja**, evitando que se calculen volúmenes irreales o se alteren los promedios del lote.
>
> 4. **Decisión 2 (Enrutamiento por Volumen):** Si las dimensiones son correctas, calcula el volumen multiplicando las tres dimensiones y aplica la regla de corte:
>    `if (volumen > 500.0f)` $\rightarrow$ la desvía a la **Banda A**.
>    `else` $\rightarrow$ la envía a la **Banda B**.
>
> 5. **Cierre y Reporte:** Al finalizar el ciclo con 'N', el programa imprime el resumen consolidado del turno con el total de cajas, la distribución por banda y el volumen promedio procesado."

---

### ⏱️ Minuto 1:50 - 3:15 | Demostración en Vivo de las Tres Pruebas
*(Ejecutas el programa en vivo en la consola de OneCompiler o terminal)*

> "Ahora voy a compilar y ejecutar el programa en vivo para validar los tres comportamientos del sistema:
>
> * **Prueba 1 (Caso Habitual - Caja Grande):**
>   - Ingreso: Ancho **10**, Alto **10**, Profundidad **8**.
>   - El sistema calcula: Volumen = **800.00 cm³**.
>   - Como 800 es mayor a 500, el mensaje confirma: *'Desviar a BANDA TRANSPORTADORA A'*. Funciona correctamente.
>   - Continuar: marco **'S'**.
>
> * **Prueba 2 (Caso Límite - Umbral de Frontera):**
>   - Ingreso: Ancho **10**, Alto **10**, Profundidad **5**.
>   - El sistema calcula exactamente **500.00 cm³**.
>   - Aquí se evalúa el borde: como 500.00 **no** es estrictamente mayor que 500.00, la condición da falso y el sistema la envía a la *'BANDA TRANSPORTADORA B'*. El comportamiento del límite es exacto.
>   - Continuar: marco **'S'**.
>
> * **Prueba 3 (Caso Inválido - Dimensión Anómala):**
>   - Supongamos que ingresa un ancho erróneo de **-5 cm**, con alto **10** y profundidad **5**.
>   - El programa intercepta el error al instante: imprime *'[ALERTA DE ERROR]: Entrada inválida detectada'* y no suma la caja a las estadísticas.
>   - Ahora marco **'N'** para cerrar el turno.
>
> * **Resultado del Reporte Final:**
>   - Vemos en consola: 2 cajas válidas procesadas (1 en Banda A y 1 en Banda B), volumen total de 1300.00 cm³ y volumen promedio de 650.00 cm³. Las estadísticas quedan perfectas."

---

### ⏱️ Minuto 3:15 - 3:45 | Reflexión Crítica de Ingeniería y Cierre
*(Mirando a la cámara)*

> "Para finalizar, durante el diseño consulté con herramientas de IA alternativas de estructuración. La IA inicialmente me sugería crear una clase con punteros dinámicos (`new`/`delete`) y vectores de objetos. 
> 
> Sin embargo, tomé la decisión de **descartar esa sugerencia para evitar sobreingeniería**: para el control de flujos en Mecatrónica, una solución procedimental limpia, bien modularizada con variables primitivas y un ciclo `do-while` es mucho más confiable, transparente y elimina riesgos de fugas de memoria.
>
> Muchas gracias por su atención, quedo atento a cualquier retroalimentación técnica en el foro."

---

## 2. PLANTILLAS DIRECTAS PARA EL FORO DE CONTROL DE FLUJOS

### A. Mensaje para tu Publicación Inicial en el Foro:
> **Asunto:** Sustentación Individual EA2 - Automatización de Clasificación en C++ - Jhoan Esteban Pérez Herrera  
> **Cuerpo del mensaje:**  
> Buenas tardes, profesor Juan Esteban y compañeros.  
> Comparto el enlace de mi video de sustentación individual para la EA2, donde presento la lógica de control, el código en C++ y la ejecución en vivo de las tres pruebas (habitual, límite e inválida) para la línea de clasificación de paquetes:  
> 🔗 **Enlace al video:** https://drive.google.com/file/d/1_K32-rnyHYCGW6WSd1mfKlbQKjIgRWQJ/view?usp=sharing  
> 🔗 **Repositorio en GitHub (Código C++):** https://github.com/estebanPerezH/EA2_POO_ClasificadorCajas  
> Quedo atento a sus observaciones y preguntas técnicas. ¡Muchos éxitos a todos!

---

### B. Réplica Técnica al Video de un Compañero (Paso 2):
*(Buscas el aporte de cualquier compañero en el foro y le comentas lo siguiente ajustando su nombre y lenguaje)*
> Hola [Nombre del Compañero], un saludo cordial.  
> Vi tu video de sustentación y me pareció muy clara la estructura de tu proyecto.  
> • **Fortaleza:** Destaco la claridad con la que explicaste el modelado del problema de tu entorno y la forma ordenada en que mostraste la ejecución de la prueba habitual en consola.  
> • **Pregunta técnica:** Al ver la estructura de tu ciclo, me surgió una inquietud técnica: ¿Cómo controla tu programa que el ciclo no se bloquee o entre en un bucle indefinido si el usuario introduce un dato no numérico o dimensiones negativas?, ¿manejas alguna validación previa o cómo se descartan esas lecturas anómalas?  
> ¡Muchos éxitos en la entrega!

---

### C. Contrarréplica a la Observación Recibida (Paso 3):
*(Cuando alguien comente en tu publicación del foro)*
> Hola [Nombre del Compañero], muchas gracias por tomarte el tiempo de revisar mi sustentación y por tu pregunta.  
> En mi solución en C++, implementé un filtro de validación temprana justo después de capturar las dimensiones:  
> `if (ancho <= 0.0f || alto <= 0.0f || profundidad <= 0.0f)`  
> Con esta condición lógica garantizo que si entra un valor no físico, el sistema emite una alerta y salta directamente al final de la iteración mediante la rama falsa, sin alterar los acumuladores ni sumar la caja a las estadísticas. Asimismo, el ciclo `do-while` finaliza de manera segura evaluando si el carácter de continuación es diferente de 'S' o 's'.  
> ¡Agradezco mucho tu retroalimentación técnica!
