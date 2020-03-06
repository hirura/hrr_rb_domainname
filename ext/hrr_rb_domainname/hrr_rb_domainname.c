#include "hrr_rb_domainname.h"

#define HRR_RB_DOMAINNAME_MAX 1024

VALUE rb_mHrrRbDomainname;

VALUE
hrr_rb_domainname_getdomainname(void)
{
  char name[HRR_RB_DOMAINNAME_MAX + 1];

  name[HRR_RB_DOMAINNAME_MAX] = '\0';

  if (getdomainname(name, HRR_RB_DOMAINNAME_MAX) < 0)
    rb_sys_fail("getdomainname");

  return rb_str_new_cstr(name);
}

VALUE
hrr_rb_domainname_setdomainname(VALUE self, VALUE arg)
{
  char *name;

  name = StringValueCStr(arg);

  if (setdomainname(name, strlen(name)) < 0)
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
