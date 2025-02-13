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
	{ 0x40bb8bfb, __VMLINUX_SYMBOL_STR(alloc_pages_current) },
	{ 0x2d3385d3, __VMLINUX_SYMBOL_STR(system_wq) },
	{ 0xd3d9c965, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x5773238, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xef4c5632, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x1ed8b599, __VMLINUX_SYMBOL_STR(__x86_indirect_thunk_r8) },
	{ 0x7381287f, __VMLINUX_SYMBOL_STR(trace_handle_return) },
	{ 0xeb17cb88, __VMLINUX_SYMBOL_STR(debugfs_create_dir) },
	{ 0x2bba8c19, __VMLINUX_SYMBOL_STR(single_open) },
	{ 0x66bca5b1, __VMLINUX_SYMBOL_STR(param_get_int) },
	{ 0xecaaca53, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0xd8e484f0, __VMLINUX_SYMBOL_STR(register_chrdev_region) },
	{ 0xf58b375a, __VMLINUX_SYMBOL_STR(__wake_up_sync) },
	{ 0x784abdf1, __VMLINUX_SYMBOL_STR(single_release) },
	{ 0x73dc6edd, __VMLINUX_SYMBOL_STR(seq_puts) },
	{ 0x7ab88a45, __VMLINUX_SYMBOL_STR(system_freezing_cnt) },
	{ 0xcdbfc112, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0xad27f361, __VMLINUX_SYMBOL_STR(__warn_printk) },
	{ 0x6729d3df, __VMLINUX_SYMBOL_STR(__get_user_4) },
	{ 0xc29957c3, __VMLINUX_SYMBOL_STR(__x86_indirect_thunk_rcx) },
	{ 0xf12b84a0, __VMLINUX_SYMBOL_STR(init_user_ns) },
	{ 0x98317f2d, __VMLINUX_SYMBOL_STR(param_ops_bool) },
	{ 0x778b8af3, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0xdffad016, __VMLINUX_SYMBOL_STR(mmput) },
	{ 0xe9574e6d, __VMLINUX_SYMBOL_STR(trace_event_buffer_reserve) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x999e8297, __VMLINUX_SYMBOL_STR(vfree) },
	{ 0x996fd208, __VMLINUX_SYMBOL_STR(param_set_int) },
	{ 0xcf931e26, __VMLINUX_SYMBOL_STR(debugfs_create_file) },
	{ 0x7a2af7b4, __VMLINUX_SYMBOL_STR(cpu_number) },
	{ 0x35e98eeb, __VMLINUX_SYMBOL_STR(debugfs_remove_recursive) },
	{ 0x6b0a3963, __VMLINUX_SYMBOL_STR(seq_read) },
	{ 0xece784c2, __VMLINUX_SYMBOL_STR(rb_first) },
	{ 0xa6682fdd, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0xb44ad4b3, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0xb8e7ce2c, __VMLINUX_SYMBOL_STR(__put_user_8) },
	{ 0x9735093f, __VMLINUX_SYMBOL_STR(trace_define_field) },
	{ 0xd38cd261, __VMLINUX_SYMBOL_STR(__default_kernel_pte_mask) },
	{ 0xe650a90, __VMLINUX_SYMBOL_STR(from_kuid) },
	{ 0x5452c135, __VMLINUX_SYMBOL_STR(device_register) },
	{ 0xe966901, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0x9b65a65f, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x51e37b22, __VMLINUX_SYMBOL_STR(freezing_slow_path) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x5a5a2271, __VMLINUX_SYMBOL_STR(__cpu_online_mask) },
	{ 0x3be256b8, __VMLINUX_SYMBOL_STR(get_task_mm) },
	{ 0xa1c76e0a, __VMLINUX_SYMBOL_STR(_cond_resched) },
	{ 0x4d9b652b, __VMLINUX_SYMBOL_STR(rb_erase) },
	{ 0x7aeb6eb6, __VMLINUX_SYMBOL_STR(trace_event_reg) },
	{ 0x92828e3c, __VMLINUX_SYMBOL_STR(debugfs_remove) },
	{ 0x9c079d54, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0xe007de41, __VMLINUX_SYMBOL_STR(kallsyms_lookup_name) },
	{ 0x69d38b8b, __VMLINUX_SYMBOL_STR(up_write) },
	{ 0x84a77c31, __VMLINUX_SYMBOL_STR(down_write) },
	{ 0x3fb012b8, __VMLINUX_SYMBOL_STR(fput) },
	{ 0x9e559b01, __VMLINUX_SYMBOL_STR(perf_trace_run_bpf_submit) },
	{ 0xad5f0017, __VMLINUX_SYMBOL_STR(perf_trace_buf_alloc) },
	{ 0xfe487975, __VMLINUX_SYMBOL_STR(init_wait_entry) },
	{ 0xdb2bb233, __VMLINUX_SYMBOL_STR(vm_insert_page) },
	{ 0xcc138140, __VMLINUX_SYMBOL_STR(__task_pid_nr_ns) },
	{ 0x32989da9, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0xa30768ec, __VMLINUX_SYMBOL_STR(__free_pages) },
	{ 0xb601be4c, __VMLINUX_SYMBOL_STR(__x86_indirect_thunk_rdx) },
	{ 0xb2fd5ceb, __VMLINUX_SYMBOL_STR(__put_user_4) },
	{ 0xa916b694, __VMLINUX_SYMBOL_STR(strnlen) },
	{ 0x166158b0, __VMLINUX_SYMBOL_STR(trace_event_ignore_this_pid) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0x6d334118, __VMLINUX_SYMBOL_STR(__get_user_8) },
	{ 0x2ea2c95c, __VMLINUX_SYMBOL_STR(__x86_indirect_thunk_rax) },
	{ 0x4482cdb, __VMLINUX_SYMBOL_STR(__refrigerator) },
	{ 0xd0d0ca14, __VMLINUX_SYMBOL_STR(trace_event_buffer_commit) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0xcbd4898c, __VMLINUX_SYMBOL_STR(fortify_panic) },
	{ 0xbeee391, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xa5526619, __VMLINUX_SYMBOL_STR(rb_insert_color) },
	{ 0x5387d4ab, __VMLINUX_SYMBOL_STR(event_triggers_call) },
	{ 0xfe768495, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0x237a015a, __VMLINUX_SYMBOL_STR(prepare_to_wait_event) },
	{ 0x6acbfc5d, __VMLINUX_SYMBOL_STR(seq_lseek) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xc770f9b2, __VMLINUX_SYMBOL_STR(trace_event_raw_init) },
	{ 0x169aef1d, __VMLINUX_SYMBOL_STR(set_user_nice) },
	{ 0xb48fef4b, __VMLINUX_SYMBOL_STR(__put_task_struct) },
	{ 0xeaac6b91, __VMLINUX_SYMBOL_STR(fget) },
	{ 0x53569707, __VMLINUX_SYMBOL_STR(this_cpu_off) },
	{ 0x942cfb36, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0xd4fa5c30, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0xca9360b5, __VMLINUX_SYMBOL_STR(rb_next) },
	{ 0x62d5d788, __VMLINUX_SYMBOL_STR(device_unregister) },
	{ 0xeb98ac2f, __VMLINUX_SYMBOL_STR(task_active_pid_ns) },
	{ 0x84c49753, __VMLINUX_SYMBOL_STR(trace_raw_output_prep) },
	{ 0x2e0d2f7f, __VMLINUX_SYMBOL_STR(queue_work_on) },
	{ 0x28318305, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0x1601f46b, __VMLINUX_SYMBOL_STR(trace_seq_printf) },
	{ 0xd13f5bab, __VMLINUX_SYMBOL_STR(dev_set_name) },
	{ 0x362ef408, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0xec43990d, __VMLINUX_SYMBOL_STR(param_ops_uint) },
	{ 0x76a81688, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x88db9f48, __VMLINUX_SYMBOL_STR(__check_object_size) },
	{ 0x17fbce60, __VMLINUX_SYMBOL_STR(sme_me_mask) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "D5E682291E363AB623FE37E");
