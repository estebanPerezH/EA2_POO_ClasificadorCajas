# Sistema Automatizado de Clasificación de Cajas en C++
**Evidencia de Aprendizaje 2 (EA2): Modeladores de Flujos: Lógica y Control en el Entorno**  
**Curso:** Programación Orientada a Objetos (Ruta Ingeniería Mecatrónica)  
**Institución:** Institución Universitaria Digital de Antioquia (IU Digital)  
**Estudiante:** Jhoan Esteban Pérez Herrera  
**Docente:** Juan Esteban Acevedo Carvajal  

---

## 📌 Descripción del Proyecto
Este proyecto implementa una solución algorítmica robusta en **C++** para automatizar el proceso de clasificación y embalaje continuo de paquetes en una fábrica de repuestos mecánicos e industriales ubicada en **Itagüí (Valle de Aburrá, Antioquia)**.

El sistema simula la captura continua de dimensiones de paquetes que viajan por una banda transportadora principal, calcula el volumen cúbico y acciona el desvío físico según la regla de corte volumétrico:
- **Banda Transportadora A:** Cajas de gran volumen ($> 500.00\text{ cm}^3$).
- **Banda Transportadora B:** Cajas compactas o de tamaño estándar ($\le 500.00\text{ cm}^3$).

### 🎥 Video de Sustentación Audiovisual (Individual)
- **Enlace de visualización en Google Drive:** [Sustentación en Video - Jhoan Esteban Pérez Herrera](https://drive.google.com/file/d/1_K32-rnyHYCGW6WSd1mfKlbQKjIgRWQJ/view?usp=sharing)

---

## ⚙️ Estructuras de Control Implementadas (Sin Sobreingeniería)
Siguiendo los lineamientos pedagógicos de la ruta de Mecatrónica, el algoritmo utiliza programación estructurada transparente:
1. **Tipos de Datos Primitivos:** Variables `float` para medidas físicas y contadores/acumuladores `int` y `float` para estadísticas del lote.
2. **Ciclo `do-while`:** Garantiza el procesamiento de al menos una primera pieza al inicio del turno y mantiene la línea activa mientras el operario confirme (`continuar == 'S'`).
3. **Manejo Temprano de Entradas Inválidas:** Condicional de seguridad `if (ancho <= 0 || alto <= 0 || profundidad <= 0)` que detecta y descarta mediciones anómalas o negativas sin corromper las estadísticas del lote.
4. **Enrutamiento y Salidas:** Condicional `if (volumen > 500.0f)` para asignación a bandas y generación del reporte consolidado al final de la sesión.

---

## 🧪 Pruebas del Sistema

| Tipo de Prueba | Dimensiones (cm) | Volumen | Decisión / Resultado | Comportamiento Observado |
| :--- | :--- | :---: | :--- | :--- |
| **1. Habitual** | $10 \times 10 \times 8$ | $800.00\text{ cm}^3$ | **Banda A** (Caja Grande) | Condición `800 > 500` evalúa a Verdadero. Desvío correcto. |
| **2. Límite** | $10 \times 10 \times 5$ | $500.00\text{ cm}^3$ | **Banda B** (Caja Estándar) | Condición `500 > 500` evalúa a Falso. Enrutamiento exacto al borde. |
| **3. Inválida** | $-5 \times 10 \times 5$ | N/A | **Alerta de Error y Rechazo** | Se intercepta la medida negativa; la pieza no suma a estadísticas. |

---

## 🚀 Guía de Compilación y Ejecución

### Opción 1: En Línea (OneCompiler)
1. Ingresar a [OneCompiler C++](https://onecompiler.com/cpp).
2. Pegar el contenido del archivo `clasificador_cajas.cpp`.
3. Presionar **Run** e ingresar los valores interactivamente por consola.

### Opción 2: Compilación Local en Terminal (MinGW GCC)
```bash
# Compilar el código fuente
g++ -std=c++11 clasificador_cajas.cpp -o clasificador.exe

# Ejecutar el programa
./clasificador.exe
```

---

## 📂 Estructura del Repositorio
```
├── clasificador_cajas.cpp      # Código fuente oficial en C++
├── EA2_POO_JhoanPerez.pdf      # Informe técnico completo en formato institucional
├── GUION_Y_SUSTENTACION_EA2.md # Guion de sustentación audiovisual y plantillas de foro
└── README.md                   # Documentación técnica del proyecto
```

