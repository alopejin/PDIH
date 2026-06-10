/**
 * @file   hello.c
 * @author Alejandro López Jiménez
 * @date   Junio 2026
 * @brief  Un LKM que muestra un mensaje de saludo al cargarse 
 *         y otro de despedida al descargarse del kernel.
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Alejandro Lopez Jimenez");
MODULE_DESCRIPTION("Modulo LKM sencillo - Seminario PDIH");
MODULE_VERSION("0.1");

static char *name = "mundo";
module_param(name, charp, S_IRUGO);
MODULE_PARM_DESC(name, "Nombre a mostrar en el log del kernel");

/** @brief Función de inicialización del LKM.
 *  @return 0 si todo va bien
 */
static int __init hello_init(void){
    printk(KERN_INFO "PDIH: Hola %s desde el modulo LKM!\n", name);
    return 0;
}

/** @brief Función de limpieza del LKM.
 *  Se ejecuta al descargar el módulo con rmmod.
 */
static void __exit hello_exit(void){
    printk(KERN_INFO "PDIH: Adios %s desde el modulo LKM!\n", name);
}

module_init(hello_init);
module_exit(hello_exit);
