﻿<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="WebUI.Config.VideoInput.Default" %>


<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>


<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">

    <asp:Panel runat="server" ID="pnlSelector">
        <asp:DropDownList runat="server" ID="ddlInput" AutoPostBack="true" 
            onselectedindexchanged="ddlInput_SelectedIndexChanged">

        </asp:DropDownList>
    </asp:Panel>

    <br /><br /><br />

    <asp:Panel runat="server" ID="pnlEnable">
        Video Input is disabled<br />
        <br />
        <asp:Button runat="server" ID="btnEnable" Text="Enable" onclick="btnEnable_Click" />
    </asp:Panel>

    <asp:Panel runat="server" ID="pnlConfig" Visible="false">
        <table>
            <tr>
                <td>Codec</td>
                <td></td>
            </tr>
            <tr>
                <td>Resolution</td>
                <td></td>
            </tr>
            <tr>
                <td>Frame Rate</td>
                <td></td>
            </tr>
            <tr>
                <td></td>
                <td>
                    <asp:Button runat="server" ID="btnSave" Text="Save" onclick="btnSave_Click" />
                    <asp:Button runat="server" ID="btnCancel" Text="Cancel" 
                        onclick="btnCancel_Click" />
                </td>
            </tr>
        </table>
        <asp:Button runat="server" ID="btnDisable" Text="Disable" 
            onclick="btnDisable_Click" />
    </asp:Panel>

</asp:Content>
