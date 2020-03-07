#include "hrr_rb_domainname.h"

#define HRR_RB_DOMAINNAME_MAX 1024

VALUE rb_mHrrRbDomainname;

/*
 * A wrapper around getdomainname. Returns domainname that is set on the machine.
 *
 * @raise [Errno::EINVAL] when the name is too long.
 * @return [String] domainname that is set on the machine.
 */
VALUE
hrr_rb_domainname_getdomainname(void)
{
  char name[HRR_RB_DOMAINNAME_MAX + 1];

  name[HRR_RB_DOMAINNAME_MAX] = '\0';

  if (getdomainname(name, HRR_RB_DOMAINNAME_MAX) < 0)
    rb_sys_fail("getdomainname");

  return rb_str_new_cstr(name);
}

/*
 * A wrapper around setdomainname. Returns domainname that is updated on the machine.
 *
 * @param [String] name domainname to be set
 * @raise [Errno::EFAULT] when the name pointed outside of user address space.
 * @raise [Errno::EINVAL] when the name is too long.
 * @raise [Errno::EPERM ] when the caller did not have the CAP_SYS_ADMIN capability in the user namespace associated with its UTS namespace (see namespaces(7)).
 * @return [String] domainname that is updated on the machine
 */
VALUE
hrr_rb_domainname_setdomainname(VALUE self, VALUE name)
{
  char *dname = StringValueCStr(name);

  if (setdomainname(dname, strlen(dname)) < 0)
    rb_sys_fail("setdomainname");

  return hrr_rb_domainname_getdomainname();
}

void
Init_hrr_rb_domainname(void)
{
  rb_mHrrRbDomainname = rb_define_module("HrrRbDomainname");
  rb_define_singleton_method(rb_mHrrRbDomainname, "get",           hrr_rb_domainname_getdomainname, 0);
  rb_define_singleton_method(rb_mHrrRbDomainname, "getdomainname", hrr_rb_domainname_getdomainname, 0);
  rb_define_singleton_method(rb_mHrrRbDomainname, "set",           hrr_rb_domainname_setdomainname, 1);
  rb_define_singleton_method(rb_mHrrRbDomainname, "setdomainname", hrr_rb_domainname_setdomainname, 1);
}
