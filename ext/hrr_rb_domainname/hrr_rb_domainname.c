#include "hrr_rb_domainname.h"

VALUE rb_mHrrRbDomainname;

void
Init_hrr_rb_domainname(void)
{
  rb_mHrrRbDomainname = rb_define_module("HrrRbDomainname");
}
