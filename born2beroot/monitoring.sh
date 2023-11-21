#!/bin/bash

# Define colors
NC='\033[0m' # No Color
GREEN='\033[0;32m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
RED='\033[0;31m'

# Define the function to display the table
display_info() {
  printf "| ${CYAN}%-16s${NC} | ${GREEN}%-19s${NC} |\n" "$1" "$2"
}

while true; do
  # Collecte des informations
  architecture=$(uname -a)
  cpu_physical=$(grep -c "physical id" /proc/cpuinfo)
  vcpu=$(grep -c "processor" /proc/cpuinfo)
  mem_usage=$(free -m | awk 'NR==2{printf "%s/%sMB (%.2f%%)", $3,$2,$3*100/$2 }')
  disk_usage=$(df -h | awk '$NF=="/"{printf "%d/%dGB (%s)", $3,$2,$5}')
  cpu_load=$(top -bn1 | grep load | awk '{printf "%.2f%%", $(NF-2)}')
  last_boot=$(who -b | awk '{print $3 " " $4}')
  lvm_use=$(if [ $(lsblk | grep -c "lvm") -gt 0 ]; then echo "yes"; else echo "no"; fi)
  tcp_connections=$(ss -s | grep "estab" | awk '{print $4 " ESTABLISHED"}')
  users_log=$(who | wc -l)
  ip_address=$(hostname -I | awk '{print $1}')
  mac_address=$(ip link | awk '/ether/ {print $2}')
  sudo_cmd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

  clear

  printf "${BLUE}==========================================${NC}\n"
  display_info "Architecture" "$architecture"
  display_info "CPU physical" "$cpu_physical"
  display_info "vCPU" "$vcpu"
  display_info "Memory Usage" "$mem_usage"
  display_info "Disk Usage" "$disk_usage"
  display_info "CPU load" "$cpu_load"
  display_info "Last boot" "$last_boot"
  display_info "LVM use" "$lvm_use"
  display_info "TCP Connections" "$tcp_connections"
  display_info "User log" "$users_log"
  display_info "Network IP" "$ip_address"
  display_info "MAC Address" "$mac_address"
  display_info "Sudo" "$sudo_cmd commands"
  printf "${BLUE}==========================================${NC}\n"

  # Pause de 10 minutes
  sleep 600
done
