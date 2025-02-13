#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x7ef2b274, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xd3cd1b85, __VMLINUX_SYMBOL_STR(kmem_cache_destroy) },
	{ 0x754d539c, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0xa7bf554d, __VMLINUX_SYMBOL_STR(generic_file_open) },
	{ 0xb1bf2f8, __VMLINUX_SYMBOL_STR(vfs_llseek) },
	{ 0x778b8af3, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x24428be5, __VMLINUX_SYMBOL_STR(strncpy_from_user) },
	{ 0xb44ad4b3, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0xc00a6eeb, __VMLINUX_SYMBOL_STR(kernel_read) },
	{ 0x42d5399d, __VMLINUX_SYMBOL_STR(misc_register) },
	{ 0x9b65a65f, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x76e584bd, __VMLINUX_SYMBOL_STR(kmem_cache_free) },
	{ 0x9c079d54, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0xe007de41, __VMLINUX_SYMBOL_STR(kallsyms_lookup_name) },
	{ 0x3fb012b8, __VMLINUX_SYMBOL_STR(fput) },
	{ 0xfa061c62, __VMLINUX_SYMBOL_STR(shmem_file_setup) },
	{ 0xc6cbbc89, __VMLINUX_SYMBOL_STR(capable) },
	{ 0x7e483b00, __VMLINUX_SYMBOL_STR(kmem_cache_alloc) },
	{ 0xc0b622d8, __VMLINUX_SYMBOL_STR(unregister_shrinker) },
	{ 0xa916b694, __VMLINUX_SYMBOL_STR(strnlen) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xca3b4a47, __VMLINUX_SYMBOL_STR(vfs_fallocate) },
	{ 0x2ea2c95c, __VMLINUX_SYMBOL_STR(__x86_indirect_thunk_rax) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0xcbd4898c, __VMLINUX_SYMBOL_STR(fortify_panic) },
	{ 0xbf0dc38b, __VMLINUX_SYMBOL_STR(kmem_cache_create) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x2f074499, __VMLINUX_SYMBOL_STR(register_shrinker) },
	{ 0x362ef408, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0xc3da4af4, __VMLINUX_SYMBOL_STR(misc_deregister) },
	{ 0x88db9f48, __VMLINUX_SYMBOL_STR(__check_object_size) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "ABD6533983CA72B3009C226");
