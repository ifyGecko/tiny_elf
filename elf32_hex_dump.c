#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

int main(int argc, char** argv){
  int fd;
  Elf32_Ehdr e_hdr;
  Elf32_Phdr p_hdr;
  
  if(argc == 2){
    fd = open(argv[1], O_RDONLY);
    
    read(fd, &e_hdr, sizeof(Elf32_Ehdr));
    lseek(fd, e_hdr.e_phoff, SEEK_SET);
    read(fd, &p_hdr, sizeof(Elf32_Phdr));

    printf("ELF HEADER\n");
    printf("e_ident:     ");
    for(int i = 0; i < EI_NIDENT-1; ++i){
      printf("%02X", e_hdr.e_ident[i]);
    }
    printf("\ne_type:      %04X\n", e_hdr.e_type);
    printf("e_machine:   %04X\n", e_hdr.e_machine);
    printf("e_version:   %08X\n", e_hdr.e_version);
    printf("e_entry:     %08X\n", e_hdr.e_entry);
    printf("e_phoff:     %08X\n", e_hdr.e_phoff);
    printf("e_shoff:     %08X\n", e_hdr.e_shoff);
    printf("e_flags:     %08X\n", e_hdr.e_flags);
    printf("e_ehsize:    %04X\n", e_hdr.e_ehsize);
    printf("e_phentsize: %04X\n", e_hdr.e_phentsize);
    printf("e_phnum:     %04X\n", e_hdr.e_phnum);
    printf("e_shentsize: %04X\n", e_hdr.e_shentsize);
    printf("e_shnum:     %04X\n", e_hdr.e_shnum);
    printf("e_shstrndx:  %04X\n\n", e_hdr.e_shstrndx);

    printf("PROGRAM HEADER\n");
    printf("p_type:      %04X\n", p_hdr.p_type);
    printf("p_offset:    %04X\n", p_hdr.p_offset);
    printf("p_vaddr:     %04X\n", p_hdr.p_vaddr);
    printf("p_paddr:     %04X\n", p_hdr.p_paddr);
    printf("p_filesz:    %04X\n", p_hdr.p_filesz);
    printf("p_memsz:     %04X\n", p_hdr.p_memsz);
    printf("p_flags:     %04X\n", p_hdr.p_flags);
  }
  return 0;
}
