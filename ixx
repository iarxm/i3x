#!/bin/env bash

# load functions eg _stf
source "$(which i3s)" load

# prgs

#_stx()     { st -c ${@} & }
#_sty()     { st -c "${class}" ${@} & sleep 0.4; }
#_sti()     { st -c "${1}" zsh -i -c "${2}" & }
#_nvx()     { nvim -c "lua require'auto.odo'.${1}()"; }
_vxf()     { _xxf "${1}" 'st -c '"${1}"' -e nvim -c "lua require'\''auto.odo'\''.'${2}'()"'; }
_vxx()     { st -c "${1}" -e nvim -c "lua require'auto.odo'.${2}()" ; }
_voa()     { _vxx voa oa & }
_vma()     { _vxx vma ma & }
_vmj()     { _vxx vmj mj & }
_vml()     { _vxx vml ml & }
_vfoa()    { _vxf vfoa oa & }
_vfma()    { _vxf vfma ma & }
_vfua()    { _vxf vfua ua & }
_vfub()    { _vxf vfub ub & }
_vds_ev()  { st -c ds -e nvim ~/da/ds/ev --cmd "cd ~/da/ds/ev" ; }
_mutt_ix() { st -c "mlx" neomutt -e "push '<change-folder>=ii<enter>'" & }
_mutt_iy() { st -c "mlx" neomutt -e "push '<change-folder>=ii<enter><sidebar-toggle-visible><enter>'" & }
_mutt_ib() { st -c "mlx" neomutt -e "push '<change-folder>=ii<enter>bibu'" & }
_mutt_ii() { _mutt_ix; }
_qb_o365() { qb win "https://outlook.office365.com/mail/" & }
_qb_gpt()  { qb win "https://chat.openai.com" & }
_qb_mlcx() { qb win "https://contacts.google.com" & }
_qb_mlcy() { qb tab "https://outlook.office365.com/people/" & }
_qb_cal()  { qb win "https://calendar.notion.so/" & }
_qb_noti() { qb win "https://notion.so/" & }
_qb_ml()   { _qb_gpt; }
_qb_mlpv() { qb m; }
_au_fl()   { st -c "flau" -e vimpc & }
_au()      { st -c "au" -e vimpc & }
_nnn()     { st -c nnn -e nnn & }
_nnf1()    { _stf "nnf1" 'nnn -a'; }
_nnf2()    { _stf "nnf2" 'nnn -a'; }
_nnf3()    { _stf "nnf3" 'nnn -a'; }
_rename()  { st -c "nnf-renamer" -e qmv -d --format destination-only ${1} 2>/dev/null & }

_ml_split()
{
    _mutt_ii
    sleep 3
    i3-msg '[class="mlx"] focus'
    i3-msg "split h"
    _qb_mlpv
    sleep 3; i3-msg "focus right"
}

_ws_oo()
{
  _l_tabd
  _qb_cal
  _voa
}

_ws_ml()
{
  _l_tabd
  _qb_ml
  _mutt_ii
  _vml
}

_ws_ai()     { _qb_gpt; }
_ws_mj()     { _vma; }
_ws_au()     { _st; _au; }
_ws_sx()     { _st; }
_ws_sy()     { _st; }
_ws_rd()     { _nnn; } #todo: create custom workspace for academic reading (focused)
_ws_ds()     { _st "nvim ~/d/ds/ev --cmd "cd ~/d/ds/ev"" ; }
_ws_fl_ai()  { _ws_x "flai" "3" "_ws_ai" ; }
_ws_fl_oo()  { _ws_x "floo" "4" "_ws_oo" ; }
_ws_fl_mk()  { _ws_x "flmk" "3" "_ws_mk" ; }
_ws_fl_ml()  { _ws_x "flml" "3" "_ws_ml" ; }
_ws_fl_mj()  { _ws_x "flmj" "3" "_ws_mj" ; }
_ws_fl_au()  { _ws_x "flau" "2" "_ws_au" ; }
_ws_fl_sx()  { _ws_x "flsx" "2" "_ws_sx" ; }
_ws_fl_sy()  { _ws_x "flsy" "2" "_ws_sy" ; }
_ws_fl_ds()  { _ws_x "flds" "2" "_ws_ds" ; }
_ws_ab_rd()  { _ws_y "xrd" "_ws_rd" ; }
_ws_ab_au()  { _ws_y "xau" "_ws_au" ; }
_ws_ab_ai()  { _ws_y "xai" "_ws_ai" ; }
_ws_ab_sx()  { _ws_y "xsx" "_ws_sx" ; }
_ws_ab_sy()  { _ws_y "xsy" "_ws_sy" ; }
_ws_ab_sy()  { _ws_y "xds" "_ws_ds" ; }
_ws_ab_oo()  { _ws_y "xoo" "_ws_oo" ; }
_ws_ab_mj()  { _ws_y "xmj" "_ws_mj" ; }
_ws_ab_mk()  { _ws_y "xmk" "_ws_mk" ; }
_ws_ab_ml()  { _ws_y "xml" "_ws_ml" ; }

_ws_ml_contain()
{
    # TODO: container & non-floating, within any workspace 'x'
    _wcont_init
    _ws_ml
    _wcont
}

# URLS
# TODO: separate personal program configs into separate file
urls=()
url_soc_a()
{
    urls+=("https://www.facebook.com/iarom.ma")
    urls+=("https://www.instagram.com/iarom.madden/")
}
url_soc_b()
{
    url_soc_a
    urls+=("https://twitter.com/imaddsy")
    urls+=("https://publish.socialchamp.io/app/v2/engage/inbox?itemType=all&itemStatus=unread")
}
url_oo()
{
    urls+=("notion.so")
    urls+=("https://chat.openai.com/chat")
}
url_oox()
{
    # calendar.google.com opened with norestore func
    urls+=("contacts.google.com")
    urls+=("calendar.google.com")
    urls+=("https://habitica.com/")
}
url_cm_a()
{
    urls+=("web.whatsapp.com")
    urls+=("https://business.facebook.com/latest/inbox/")
}

# specifi spaces

q_wa() { qb xwin web.whatsapp.com ;}
w_xx() { qb win chat.openai.com; }
w_xy() {
    qb win notion.so
    #qb x win calendar.google.com & sleep 2s
    #qb w.oo.wins & sleep 3s
    #qb win notion.so & sleep 2s
    #qb tab notion.so
    #firefox calendar.google.com & # firefox to avoid qtwebengine issues with these sites
        # just use morgen for the mo
    #qb tab chat.openai.com
}

_pomx()
{
    for R in $(printf "%s\n" "${poms}" | grep R -o)
    do
        read -r line
        echo "$(pomo status)" || exit 1
    done
}

_pomf1() { poms=$(pomodoro status --format "%R ⏱ %c/%g 🍅\n%d"); }
_pomf2() { poms=$(pomo status); }
_pom1()  { _pomf1; _pomx;}
_pom2()  { _pomf2; _pomx;}

_main() {
    
    cmd="${1}" && [ -n "${1}" ] && shift 1
    
    #_ini
    
    case ${cmd} in
        # workspace
        flai|ws-flai)     _ws_fl_ai ;;
        floo|ws-floo)     _ws_fl_oo ;;
        flds|ws-flds)     _ws_fl_ds ;;
        flmj|ws-flmj)     _ws_fl_mj ;;
        flmk|ws-flml)     _ws_fl_mk ;;
        flml|ws-flml)     _ws_fl_ml ;;
        flau|ws-flau)     _ws_fl_au ;;
        flrd|ws-flrd)     _ws_fl_rd ;;
        flsx|ws-flsx)     _ws_fl_sx ;;
        flsy|ws-flsy)     _ws_fl_sy ;;
        xai|wxai)         _ws_ab_ai ;;
        xoo|wxoo)         _ws_ab_oo ;;
        xmj|wxmj)         _ws_ab_mj ;;
        xmk|wxmk)         _ws_ab_mk ;;
        xml|wxml)         _ws_ab_ml ;;
        xau|wxau)         _ws_ab_au ;;
        xrd|wxrd)         _ws_ab_rd ;;
        xsx|wxsx)         _ws_ab_sx ;;
        xsy|wxsy)         _ws_ab_sy ;;
        # windows
        voa)              _voa ;;
        vma)              _vma ;;
        vma)              _vma ;;
        vfoa)             _vfoa ;;
        vfma)             _vfma ;;
        vfua)             _vfua ;;
        vfub)             _vfub ;;
        # apps
        nnf1)             _nnf1 ;;
        nnf2)             _nnf2 ;;
        nnf3)             _nnf3 ;;
        au)               _au ;;
        ml)               _mutt_ii ;;
        mlb)              _mutt_ib ;;
        pomx)             _pomx ;;
        pomy)             _pomy ;;
        # functions
        r|rename)         _rename "${@}" ;;
        *|custom)         ${@} ;;
    esac
}

_main "${@}"
