// ==============================================================================
// INSTITUCIÓN UNIVERSITARIA DIGITAL DE ANTIOQUIA - IU DIGITAL
// Asignatura: Programación Orientada a Objetos (Ruta Ingeniería Mecatrónica)
// Evidencia de Aprendizaje 2 (EA2): Modeladores de Flujos: Lógica y Control en el Entorno
// 
// Estudiante: Jhoan Esteban Pérez Henao
// Docente: Juan Esteban Acevedo Carvajal
// 
// Contexto Plausible: Automatización de la línea de embalaje y clasificación de cajas 
// en una fábrica de repuestos industriales en el Valle de Aburrá.
// ==============================================================================

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // -------------------------------------------------------------------------
    // 1. DECLARACIÓN DE VARIABLES Y TIPOS DE DATOS
    // -------------------------------------------------------------------------
    // Variables para almacenar las medidas de la caja ingresadas por consola
    float ancho = 0.0f;
    float alto = 0.0f;
    float profundidad = 0.0f;
    float volumen = 0.0f;

    // Variables acumuladoras y contadores de control para el lote continuo
    int totalCajas = 0;
    int cajasBandaA = 0;
    int cajasBandaB = 0;
    float volumenTotal = 0.0f;

    // Variable para controlar la condición de terminación del ciclo
    char continuar = 'S';

    cout << "==========================================================" << endl;
    cout << "   SISTEMA DE CLASIFICACION AUTOMATIZADA DE CAJAS        " << endl;
    cout << "     Fabrica de Repuestos - Valle de Aburra (EA2)        " << endl;
    cout << "==========================================================" << endl;

    // -------------------------------------------------------------------------
    // 2. ESTRUCTURA REPETITIVA (CICLO do-while)
    // Se utiliza un ciclo do-while porque el proceso en la banda transportadora
    // debe ejecutar al menos una lectura de caja y continuar mientras el 
    // operario confirme que hay más piezas en el turno (continuar == 'S' o 's').
    // -------------------------------------------------------------------------
    do {
        cout << "\n--- Registro de Caja #" << (totalCajas + 1) << " ---" << endl;
        
        cout << "Ingrese el ancho de la caja (cm): ";
        cin >> ancho;
        cout << "Ingrese el alto de la caja (cm): ";
        cin >> alto;
        cout << "Ingrese la profundidad de la caja (cm): ";
        cin >> profundidad;

        // ---------------------------------------------------------------------
        // 3. ESTRUCTURA DE DECISIÓN 1: MANEJO DE ENTRADAS INVÁLIDAS
        // Validación de rango físico: ninguna dimensión puede ser negativa o cero.
        // ---------------------------------------------------------------------
        if (ancho <= 0.0f || alto <= 0.0f || profundidad <= 0.0f) {
            cout << "\n[ALERTA DE ERROR]: Entrada invalida detectada." << endl;
            cout << "Las dimensiones fisicas deben ser valores estrictamente mayores a 0." << endl;
            cout << "Esta caja no fue procesada ni sumada a las estadisticas." << endl;
        } else {
            // PROCESO: Cálculo del volumen cúbico
            volumen = ancho * alto * profundidad;
            volumenTotal += volumen;
            totalCajas++;

            cout << fixed << setprecision(2);
            cout << "\n>> Volumen de la caja: " << volumen << " cm3" << endl;

            // -----------------------------------------------------------------
            // 4. ESTRUCTURA DE DECISIÓN 2: CLASIFICACIÓN Y DESVÍO A BANDA
            // Regla de corte: si volumen > 500 cm3 va a la Banda A, si no a la Banda B.
            // -----------------------------------------------------------------
            if (volumen > 500.0f) {
                cout << ">> Decision: Desviar a BANDA TRANSPORTADORA A (Caja Grande)" << endl;
                cajasBandaA++;
            } else {
                cout << ">> Decision: Enviar a BANDA TRANSPORTADORA B (Caja Estandar/Pequena)" << endl;
                cajasBandaB++;
            }
        }

        // Pregunta para evaluar la condición de parada del ciclo
        cout << "\n¿Desea clasificar otra caja en la banda? (S/N): ";
        cin >> continuar;

    } while (continuar == 'S' || continuar == 's');

    // -------------------------------------------------------------------------
    // 5. SALIDAS Y REPORTE ESTADÍSTICO FINAL
    // -------------------------------------------------------------------------
    cout << "\n==========================================================" << endl;
    cout << "           REPORTE FINAL DEL TURNO DE CLASIFICACION       " << endl;
    cout << "==========================================================" << endl;
    cout << "Total de cajas procesadas con exito: " << totalCajas << endl;
    cout << "Cajas direccionadas a Banda A (> 500 cm3): " << cajasBandaA << endl;
    cout << "Cajas direccionadas a Banda B (<= 500 cm3): " << cajasBandaB << endl;
    cout << fixed << setprecision(2);
    cout << "Volumen total acumulado: " << volumenTotal << " cm3" << endl;
    
    if (totalCajas > 0) {
        cout << "Volumen promedio del lote: " << (volumenTotal / totalCajas) << " cm3" << endl;
    } else {
        cout << "No se registraron cajas validas durante esta sesion." << endl;
    }
    cout << "==========================================================" << endl;
    cout << "Proceso finalizado. Banda transportadora detenida." << endl;

    return 0;
}

